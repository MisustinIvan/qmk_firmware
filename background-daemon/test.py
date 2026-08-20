#!/usr/bin/env python3
import hid

VENDOR_ID = 0x3434
USAGE_PAGE = 0xFF60
USAGE = 0x61

devices = [
    d for d in hid.enumerate(VENDOR_ID)
    if d.get('usage_page') == USAGE_PAGE and d.get('usage') == USAGE
]

print(f"Found {len(devices)} matching Raw HID interfaces.")

for idx, dev_info in enumerate(devices):
    path = dev_info['path']
    if isinstance(path, str):
        path = path.encode('utf-8')
    print(f"[{idx}] Opening: {path}")

    try:
        dev = hid.Device(path=path)

        # 33-byte packet (0x00 Report ID + 32 bytes VIA custom value payload)
        pkt = bytes([0x00, 0x07, 0x01, 0x00, 0x01] + [0x00] * 28)
        bytes_written = dev.write(pkt)
        print(f"    -> Wrote {bytes_written} bytes successfully.")
        dev.close()
    except Exception as e:
        print(f"    Error: {e}")
