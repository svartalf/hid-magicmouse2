#include <linux/device.h>
#include <linux/hid.h>
#include <linux/input/mt.h>


void magicmouse2_receive_report(u8 *data, int size)
{
	switch (data[0]) {
	default:
		print_hex_dump(KERN_ALERT, "Received unknown report from mm2", DUMP_PREFIX_OFFSET, 4, 32,
			data, size, true);
	}

}

int magicmouse2_debug_get_feature(struct hid_device *hdev, const u8 feature[], u8 len) {
	u8 *buf;
	int ret;
	buf = kmemdup(feature, len, GFP_KERNEL);
	if (!buf) {
		hid_err(hdev, "unable to allocate memory for feature");
		return -ENOMEM;
	}

	ret = hid_hw_raw_request(hdev, buf[0], buf, len,
							 HID_FEATURE_REPORT, HID_REQ_GET_REPORT);

	if (ret != -EIO && ret != len) {
		hid_err(hdev, "invalid get feature response (%d) from %d request\n", ret, buf[0]);
		return ret;
	}
	return 0;
}

int magicmouse2_debug_set_feature(struct hid_device *hdev, const u8 payload[], u8 len) {
	u8 *buf;
	int ret;
	buf = kmemdup(payload, len, GFP_KERNEL);
	if (!buf) {
		hid_err(hdev, "unable to allocate memory for feature");
		return -ENOMEM;
	}

	ret = hid_hw_raw_request(hdev, buf[0], buf, len,
							 HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
	if (ret != -EIO && ret != len) {
		hid_err(hdev, "invalid set feature response (%d)\n", ret);
		return ret;
	}
	return 0;
}

//int hid_magicmouse2_set_feature_keyholed_rid(struct hid_device *hdev, u8 payload)
//{
//	u8 feature[] = { 0xff, payload };
//	return hid_magicmouse2_set_feature(hdev, feature, 2);
//}
//
//int hid_magicmouse2_get_feature_device_manager_pass_through(struct hid_device *hdev) {
//	const u8 feature[] = { 0xf0 };
//	return hid_magicmouse2_get_feature(hdev, feature, 1);
//}
//
//int hid_magicmouse2_get_feature_multitouch_pass_through(struct hid_device *hdev) {
//	const u8 feature[] = { 0xf1 };
//	return hid_magicmouse2_get_feature(hdev, feature, 1);
//}
//
//int hid_magicmouse2_get_feature_reconnect_count(struct hid_device *hdev) {
//	const u8 feature[] = { 0x4e };
//	return hid_magicmouse2_get_feature(hdev, feature, 1);
//}

// Unknown feature
static int magicmouse2_feature_0xb4(struct hid_device *hdev) {
	int ret;
	const u8 key_holed_rid[] = { 0xff, 0xb4 };
	const u8 device_pass_through[] = { 0xf0 };

	ret = magicmouse2_debug_set_feature(hdev, key_holed_rid, 2);
	if (ret)
		return ret;

	ret = magicmouse2_debug_get_feature(hdev, device_pass_through, 1);
	if (ret)
		return ret;

	return 0;
}


// Device information
static int magicmouse2_feature_0x34(struct hid_device *hdev) {
	int ret;
	const u8 key_holed_rid[] = { 0xff, 0x34 };
	const u8 device_pass_through[] = { 0xf0 };

	ret = magicmouse2_debug_set_feature(hdev, key_holed_rid, 2);
	if (ret)
		return ret;

	ret = magicmouse2_debug_get_feature(hdev, device_pass_through, 1);
	if (ret)
		return ret;

	return 0;
}

int magicmouse2_debug_probe(struct hid_device *hdev)
{
	int ret;

	ret = magicmouse2_feature_0xb4(hdev);
	if (ret)
		return ret;

	ret = magicmouse2_feature_0x34(hdev);
	if (ret)
		return ret;

	return 0;
}
