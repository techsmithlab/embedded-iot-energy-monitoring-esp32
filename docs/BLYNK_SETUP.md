# Blynk Setup (Optional)

Disabled by default (`BLYNK_ENABLED 0`).

## 1. Account + template
Sign up at https://blynk.io, create a new Template.

## 2. Suggested virtual pins

| Pin | Data |
|---|---|
| V0 | Voltage |
| V1 | Current |
| V2 | Power |
| V3 | Energy |
| V4 | Relay State |
| V5 | Wi-Fi RSSI |
| V6 | System Status |

## 3. Credentials
Copy Template ID, Template Name, and device Auth Token from the console.

## 4. ESP32 configuration

```cpp
#define BLYNK_ENABLED          1
#define BLYNK_TEMPLATE_ID      "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME    "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN       "YOUR_BLYNK_AUTH_TOKEN"
```

Never commit real values.

## 5. Install library
Install "Blynk" via Arduino Library Manager. `cloud.cpp` only compiles
Blynk code paths when `BLYNK_ENABLED` is 1.

## 6. Dashboard
Add widgets bound to V0-V6 in the Blynk app.

## Note
Current firmware treats ThingSpeak as primary; Blynk connects and runs
but sending V0-V6 values (`Blynk.virtualWrite`) is left as an extension
point once the library is installed and tested.
