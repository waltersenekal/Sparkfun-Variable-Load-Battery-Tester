1. Install PSoc Creator
2. Build the bootloader in release
3. Then build the Application

Now when you send it "B" it will go into bootload mode and present a USB HID
The Application can now bootload new versions to the board

For any future builds of the Application, you do not need to touch the bootloader again