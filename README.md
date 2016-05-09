# team-troublemakers

# The IoT maker Challenge

- Use Wind River Pulsar to connect and run
	- USB web camera, USB temperature and humidity sensors
	- OpenCV image processing, RSS client, WiFi AP
	- Use HDC Agent to push data to the Helix Device Cloud 
- Use node.js to run JavaScript apps for HDC data access and to run the web server
- Use Wind River Rocket and Helix App Cloud to:
	- Connect to Wind River Pulsar 
	- Control parking traffic lights 
- Use node-RED to manage and wire-up everything together
- Use a standard web browser to present parking and weather data
- Automatically send a tweet when you arrive at the office during bad weather

## Setting up the environment

	 boot the Pulsar Linux
	 connect the USB camera
	 connect the USB temperature and humidity sensor

## Setup the OpenCV

     mkdir libidn
     cd libidn/
     wget -d ftp://alpha.gnu.org/pub/gnu/libidn/libidn-1.9.tar.gz 
     tar xfz libidn-1.9.tar.gz 
     cd libidn-1.9
     ./configure 
     make
     make install
     export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib

	 mkdir cmake
     cd cmake/
     wget https://cmake.org/files/v3.4/cmake-3.4.1-Linux-x86_64.tar.gz
     tar -xvf cmake-3.4.1-Linux-x86_64.tar.gz 
     export PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/sbin:/root/eng-sym/cmake/cmake-3.4.1-Linux-x86_64/bin/
	 
	 git clone https://github.com/Itseez/opencv.git
     cd opencv/
	 mkdir release
     cd release/
     cmake -D CMAKE_BUILD_TYPE=RELEASE -D CMAKE_INSTALL_PREFIX=/usr/local ..
     make
	 make install
	 
## Setup the HDC agent
	
	 cd HDC
	 rpm -ivh wr-iot-agent-1.0-r0.core2_64.rpm
	 
## Setup the OpenCV image recognition application

	 cd pulsar
	 cmake CMakeLists.txt
	 make
	 
## Setup the Node RED

	 cd nodered
	 smart channel --add intel_repo type=rpm-md baseurl=https://download.01.org/iotgateway/x86_64
	 smart update
	 smart install https://download.01.org/iotgateway/x86_64/nodejs-npm-v0.10.39-r0.0.corei7_64.rpm
     smart install https://download.01.org/iotgateway/x86_64/node-npm-v0.10.39-r0.0.corei7_64.rpm
	 npm install -g --unsafe-perm node-red
	 
## Run the Node RED application
	 
	 node-red node-red-weather-parking.json &