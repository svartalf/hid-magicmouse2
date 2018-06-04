# Device information

Request ID: `0x34`

## Fields

| Start byte | Length   | Description                                    |
| ---------- | -------- | ---------------------------------------------- |
| 0          | 1        | Report ID (always `0xa3`)                      |
| 1          | 1        | Pass through report ID (always `0xf0`)         |
| 2          | 1        | Request ID (`0x34`)                            |
| 3          | 1        | Unknown, seems to be constant `0x03`           |
| 4          | 1        | Unknown, might be a battery level              |
| 5          | 1        | Unknown, seems to be constant `0x00`           |
| 6          | 6        | Unknown                                        |
| 12         | 3        | Unknown, seems to be constant `0x00 0x25 0x80` |
| 15         | till end | Device name                                    |

## TODO

1. Determine unknown data
2. Determine "Device name" field encoding

## Example 1

Response:
```
a3 f0 34 03 64 00 b8 44
d9 f2 41 72 00 25 80 4d
6f 75 73 65 20 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00
```

| Field       | Value                              |
| ----------- | ---------------------------------- |
| Device name | "Mouse " (*with space at the end*) |

## Example 2

Response:
```
a3 f0 34 03 64 00 04 4b
ed ba 09 12 00 25 80 52
61 66 61 65 6c 20 58 61
76 69 65 72 20 64 65 20
53 6f 75 7a 61 e2 80 99
73 20 4d 6f 75 73 65 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00 00
00 00 00 00 00 00 00
```

| Field       | Value                            |
| ----------- | -------------------------------- |
| Device name | "Rafael Xavier de Souza's Mouse" |
