# sample node or client Example

## Introduction

Sample code includes configuration about esp-mdf node or a client and its demo.

## Configure

To run this example, you need at least two development boards, one configured as a root node, and the other a non-root node. In this example, all the devices are non-root nodes by default.

- Root node: There is only one root node in an ESP-WIFI-MESH network. `MESH` networks can be differentiated by their `MESH_ID` and channels.
- Non-root node: Include leaf nodes and intermediate nodes, which automatically select their parent nodes according to the network conditions.

You need to go to the submenu `Example Configuration` and configure one device as a root node, and the others as non-root nodes with `make menuconfig`(Make) or `idf.py menuconfig`(CMake).

You can also go to the submenu `Component config -> MDF Mwifi`, and configure the ESP-WIFI-MESH related parameters like max number of layers, the number of the connected devices on each layer, the broadcast interval, etc.

<div align=center>
<img src="config.png" width="800">
<p> Configure the device type </p>
</div>

## Run

1. Set the event callback function; 
2. Initialize wifi, and start ESP-WIFI-MESH;
3. Create an event handler function:
	- Non-root nodes send the data packet `Hello root!` to the root node at an interval of three seconds, and wait for its reply;
	- The root node replies `Hello node！` when it receives the data.
4. Create a timer: print at the specified time the ESP-WIFI-MESH network information about layers, the signal strength and the remaining memory of the parent node.

The root node log would look like this:

<div align=center>
<img src="root_log.png" width="800">
<p> The root node log </p>
</div>
# esp32
