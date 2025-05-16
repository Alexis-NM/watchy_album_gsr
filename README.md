# Album Cover Watchface for Watchy (GSR OS)

This repository contains a custom watchface for the Watchy running GSR that displays album cover artwork in BMP format. Users can add their favorite album covers to the watchface by including the corresponding BMP images in the `images.h` file.

## Features

- Display album cover art on the watch face
- Automatic rotation through a customizable list of albums
- Simple integration: add new covers by updating `images.h`
- Lightweight and efficient: built for GSR on Watchy

## Getting Started

### Prerequisites

- Watchy development environment set up with platform.io
- A Watchy device running GSR

## Adding New Album Covers

To add a new album cover image:

1. Convert your album cover image to a compatible BMP format (monochrome, 200×200 pixels).
2. Generate a C array from the BMP file.
3. Add the generated array to `images.h`
4. Update the `albums` array to include your new image name.
5. Recompile and upload the firmware to your Watchy.

## Usage

- Once loaded, the watchface will cycle through the album covers.

## Compatibility

- **Platform:** Watchy
- **Operating System:** GSR
- **Display:** 200×200 monochrome screen

## Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request for bug fixes or enhancements.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
