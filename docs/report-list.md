# Magic mouse 2 feature reports

## Known Device manager reports

* `0x34` - [Device information](https://github.com/svartalf/hid-magicmouse2/blob/master/docs/request-device-information.md)

## Unknown Device manager reports

### 0xb4

Response example

```0xa3 0xf0 0xb4 0x08 0x04```

### 0x90

Seems to be a battery status. HID descriptor from the debugfs' `rdesc` file:

```
  INPUT(144)[INPUT]
    Field(0)
      Application(ff00.0014)
      Usage(3)
        Power Device.Good
        Battery System.Charging
        Battery System.0046
      Logical Minimum(0)
      Logical Maximum(1)
      Physical Minimum(-1279)
      Physical Maximum(1279)
      Unit Exponent(-3)
      Unit(English Linear : Inch)
      Report Size(1)
      Report Count(3)
      Report Offset(0)
      Flags( Variable Absolute )
    Field(1)
      Application(ff00.0014)
      Usage(1)
        Battery System.0065
      Logical Minimum(0)
      Logical Maximum(255)
      Physical Minimum(-1279)
      Physical Maximum(1279)
      Unit Exponent(-3)
      Unit(English Linear : Inch)
      Report Size(8)
      Report Count(1)
      Report Offset(8)
      Flags( Variable Absolute )
```

Response example

**TODO**

### 0xe0

Response example

```0xa3 0xf0 0xe0 0x00 0x00 0x00 0x00```

### 0xc5

Response example

```0xa3 0xf0 0xc5 0x03```
