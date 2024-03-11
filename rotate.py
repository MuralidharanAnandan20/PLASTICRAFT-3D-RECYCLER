import serial
import time
import cv2  # Assuming you use OpenCV for image processing

arduino_port = "COM12"  # Replace with your Arduino port
baud_rate = 9600
ser = serial.Serial(arduino_port, baud_rate)
time.sleep(2)  # Wait for Arduino to initialize

# Function to identify plastic type using CNN
def identify_plastic_type(image):
    # Implement your CNN logic here to identify the plastic type
    # Return the identified type as an integer (1 to 7)
    # Example: return 1

# Capture an image using your camera or load an image from file
image = cv2.imread("path/to/image.jpg")

# Identify plastic type using CNN
plastic_type = identify_plastic_type(image)

# Send plastic type to Arduino
ser.write(str(plastic_type).encode())

# Allow time for the motor to rotate
time.sleep(2)

ser.close()  # Close the serial connection

