# Magic Mouse 2 reports

All non-standard HID reports are made in a two-phase requests.

First of all you need to call "special" *set feature report* `key-holed rid`
and pass your request into it.

`0xff` byte is constant and `0x34` is representing request type.

```c
u8 feature[] = { 0xff, 0x34 };
hid_hw_raw_request(hdev, feature[0], *feature, 2,
    HID_FEATURE_REPORT, HID_REQ_SET_REPORT);
```

After that call another one "special" *get feature report*
should be called (named `Device manager pass through report`)
which will return response for the previous feature request.

`{ 0xf0 }` request is always the same.

```c
u8 feature[] = { 0xf0 }
response = hid_hw_raw_request(hdev, feature[0], *feature, 1,
    HID_FEATURE_REPORT, HID_REQ_GET_REPORT);
```

Now `response` will contain expected response from the device
if anything went okay.

## Notes

For all examples `hdev` variable have a `struct hid_device *hdev` type,
as in all kernel `hid_*` functions.
