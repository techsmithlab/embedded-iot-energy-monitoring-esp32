# Safety

**230V AC is dangerous and potentially fatal. Read this before touching
any mains wiring in this project.**

- Do not build mains wiring on a breadboard.
- Do not touch exposed mains terminals.
- Disconnect power before modifying any wiring.
- Use appropriate insulation on all mains-side connections.
- Use proper terminals and an enclosure for mains wiring.
- Use appropriate fuse/protection on the Live conductor.
- Protective earth must never be connected to ESP32 GND or any
  low-voltage logic ground in this project.
- Low-voltage electronics must remain isolated from dangerous mains
  conductors at all times.
- Final mains wiring and testing should be performed or verified by a
  qualified electrician or other competent person.
- This project does not present itself as electrically certified.
- This project does not claim compliance with any electrical safety
  standard unless independently verified (it has not been, as of this
  writing).

## If you are not confident about mains wiring

Stop. The low-voltage side (ESP32, sensor logic pins, relay coil, LCD,
Wi-Fi, cloud dashboard) can be fully developed, tested, and demonstrated
without ever energizing the mains/AC portion of the circuit.
