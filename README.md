[![E+E_Logo](./images/epluse-logo.png)](https://www.epluse.com/en/)

# TEE501 I2C with Arduino


![TEE501](./images/TEE501.png) 


<!--[![button1](./images/learn-more.png)](https://epluse.com/products/temperature-measurement/temperature-sensing-element/tee501/)  --> 
[![button2](./images/data-sheet.png)](https://www.epluse.com/fileadmin/data/product/tee501/datasheet_TEE501.pdf) 



## QUICK START GUIDE  

### Components 
- TEE501
- Arduino
- Breadboard 
- Wire jumper cable <br>

| Step |                                                                                                                                                             |
|------|-------------------------------------------------------------------------------------------------------------------------------------------------------------|
| 1    | Connect the TEE501 sensor module with Arduino according to the following scheme:<br>__Please note: For this connection scheme the I2C address is 0x48.__ <br>  [<img src="images/TEE501_arduino.png" width="35%"/>](images/TEE501_arduino.png)[<img src="images/TEE501_breakoutboard_arduino.png" width="35%"/>](images/TEE501_breakoutboard_arduino.png)|
| 2    | Download and install the Arduino IDE (https://www.arduino.cc/en/software). Version >1.8.7 recommended.                                                            |
| 3    | Download the ZIP File of this project.|
| 4    | Open the arduino software.|
| 5    | Go to: <br>[<img src="images/add_library.png" width="550"/>](images/add_library.png) |
| 6    | Search for the downloaded ZIP File and open it.|
| 7    | Go to:<br>[<img src="images/open_file.png" width="500"/>](images/open_file.png)|
| 8    | Connect the Arduino to your PC via the USB cable. Select Board “Arduino Uno” and the appropriate COM-Port from Tools menu and upload the sketch |
| 9    | When the upload is finished, open the the "Serial Monitor" with the key combination (Control + Shift + M) or via the menu bar: <br> [<img src="images/serial_Monitor.png" width="400"/>](images/serial_Monitor.png) |

### I2C address
The sensor‘s I2C base address is 0x48 (without R/W bit). Pins A1...A3 overrule the I2C base address.(for more information check the data sheet) <br>
To make it easier to find a TEE501 and its I2C address, there is a function contained in this library called "findSensor". <br>
### No matching I2C address
You have two ways to match the I2C addresses. The first would be to call the library in the Arduino file with the correct address. Or you can change the connections to the pins A1 to A3.
<br> 





<br>

## License 
See [LICENSE](LICENSE).
