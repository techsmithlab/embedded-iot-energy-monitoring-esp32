# Contributing

Thanks for your interest in improving this project.

## Ground rules

- **Never commit real credentials.** `config.h` is gitignored - edit
  `config.example.h` for template/placeholder changes only.
- **Never claim test results that weren't actually performed.** Label
  unvalidated features `NOT TESTED`, `PLANNED`, or `REQUIRES VALIDATION`.
- **Keep pin mappings consistent.** If you change a GPIO assignment,
  update `config.h`, every affected `test/` sketch, and every doc under
  `docs/` and `hardware/` that references it.
- **Safety first.** Any change touching AC/mains-related documentation
  must keep the warnings in `docs/SAFETY.md` intact and prominent.

## How to contribute

1. Fork the repository and create a feature branch.
2. Make your changes, keeping firmware modules focused (one
   responsibility per `.h`/`.cpp` pair).
3. If you touch calibration or measurement logic, update
   `docs/SENSOR_CALIBRATION.md` and `docs/LIMITATIONS.md` accordingly.
4. Test on real hardware where possible, and note what you tested (and
   what you didn't) in your pull request description.
5. Open a pull request describing what changed and why.

## Code style

- Follow the existing modular structure (`sensors`, `display`,
  `relay_control`, `energy`, `wifi_manager`, `cloud`, `calibration`).
- Prefer `millis()`-based non-blocking timing over `delay()` in the main
  firmware loop.
- Comment any assumption that depends on the specific hardware module
  used (relay logic polarity, LCD I2C address, sensor supply voltage)
  rather than hard-coding it silently.
