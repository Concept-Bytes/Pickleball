# Pickleball
Pickleball paddle tracker

This project is built in arduino cloud in order to track your pickleball paddle live while you play.

## Prerequisites

Before you begin, ensure you have the following:
- An Arduino board set up with necessary components.
- Arduino IDE installed on your computer.
- Basic understanding of Arduino programming.
![wiring](https://github.com/Concept-Bytes/Pickleball/assets/15364440/946d7d52-bc45-4d7a-a7b7-cd917f46978d)

## Installation

1. **Clone the Repository**

   Clone or download the repository containing the Arduino code.

2. **Upload the Code**

   Open the Arduino IDE, navigate to File > Open, and select the downloaded `.ino` file from the repository.

   Connect your Arduino board to your computer using a USB cable.

   Select the correct board and port from the Tools menu.

   Click the "Upload" button in the Arduino IDE to upload the code to your Arduino board.

    
## Usage

After uploading the code to your Arduino board, your pickleball paddle tracker is ready to use. Here's how it works:

- The accelerometer sensor attached to your paddle measures acceleration during gameplay.
- The Arduino board calculates the velocity of your paddle swings based on the acceleration data.
- The code tracks the number of hits (swings) and the maximum speed (in MPH) achieved by your paddle.

## Contributing

Contributions to this Arduino project are welcome! If you have ideas for improvements or new features, feel free to fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the MIT License - see the LICENSE file in the repository for details.
