# Network Scanner


<pre>
$$\   $$\            $$\                                       $$\              $$$$$$\                                                             
$$$\  $$ |           $$ |                                      $$ |            $$  __$$\                                                            
$$$$\ $$ | $$$$$$\ $$$$$$\   $$\  $$\  $$\  $$$$$$\   $$$$$$\  $$ |  $$\       $$ /  \__| $$$$$$$\ $$$$$$\  $$$$$$$\  $$$$$$$\   $$$$$$\   $$$$$$\  
$$ $$\$$ |$$  __$$\\_$$  _|  $$ | $$ | $$ |$$  __$$\ $$  __$$\ $$ | $$  |      \$$$$$$\  $$  _____|\____$$\ $$  __$$\ $$  __$$\ $$  __$$\ $$  __$$\ 
$$ \$$$$ |$$$$$$$$ | $$ |    $$ | $$ | $$ |$$ /  $$ |$$ |  \__|$$$$$$  /        \____$$\ $$ /      $$$$$$$ |$$ |  $$ |$$ |  $$ |$$$$$$$$ |$$ |  \__|
$$ |\$$$ |$$   ____| $$ |$$\ $$ | $$ | $$ |$$ |  $$ |$$ |      $$  _$$<        $$\   $$ |$$ |     $$  __$$ |$$ |  $$ |$$ |  $$ |$$   ____|$$ |      
$$ | \$$ |\$$$$$$$\  \$$$$  |\$$$$$\$$$$  |\$$$$$$  |$$ |      $$ | \$$\       \$$$$$$  |\$$$$$$$\\$$$$$$$ |$$ |  $$ |$$ |  $$ |\$$$$$$$\ $$ |      
\__|  \__| \_______|  \____/  \_____\____/  \______/ \__|      \__|  \__|       \______/  \_______|\_______|\__|  \__|\__|  \__| \_______|\__|      
                                                                                                                                                    
~ Abhinandan Khurana                                                                                                                                                    
                                                                                                                                                    

</pre>
<br>


### This is a python based command line Network Scanner utility, which takes input as an argument for the exact IP address or the relative IP Address range you wish to do the Network Scan for and returns all the available IP addresses with their MAC addresses on your current Network.


<hr><br>


### NOTE: It will work with both, python2 and python3. You just need to install scapy module for both.
### Installation for scapy -->
<code>pip install scapy</code>

### OR

<code>pip3 install scapy-python3</code>

## How to use?

<code>
USE --help for help menu (sudo python3 network_scanner.py --help)</code>



### Example -->

<code>sudo python3 network_scanner.py -t 192.168.137.2 </code><br>
<code>sudo python3 network_scanner.py --target 192.168.137.1/24</code>
