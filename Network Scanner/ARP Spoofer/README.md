# ARP Spoofer


<pre>
                                                                                       .-----.        .-----.                                       
                                                                                      '   _    \     '   _    \                                     
                _________   _...._                         _________   _...._       /   /` '.   \  /   /` '.   \             __.....__              
                \        |.'      '-.                      \        |.'      '-.   .   |     \  ' .   |     \  '   _.._  .-''         '.            
          .-,.--.\        .'```'.    '.                     \        .'```'.    '. |   '      |  '|   '      |  '.' .._|/     .-''"'-.  `. .-,.--.  
    __    |  .-. |\      |       \     \                     \      |       \     \\    \     / / \    \     / / | '   /     /________\   \|  .-. | 
 .:--.'.  | |  | | |     |        |    |                 _    |     |        |    | `.   ` ..' /   `.   ` ..' /__| |__ |                  || |  | | 
/ |   \ | | |  | | |      \      /    .                .' |   |      \      /    .     '-...-'`       '-...-'`|__   __|\    .-------------'| |  | | 
`" __ | | | |  '-  |     |\`'-.-'   .'                .   | / |     |\`'-.-'   .'                                | |    \    '-.____...---.| |  '-  
 .'.''| | | |      |     | '-....-'`                .'.'| |// |     | '-....-'`                                  | |     `.             .' | |      
/ /   | |_| |     .'     '.                       .'.'.-'  / .'     '.                                           | |       `''-...... -'   | |      
\ \._,\ '/|_|   '-----------'                     .'   \_.''-----------'                                         | |                       |_|      
 `--'  `"                                                                                                        |_|                                



~ Abhinandan Khurana

</pre>

This is a Python based command line ARP Spoofer utility, which takes input as arguments for the exact target IP and gateway IP for which you wish to Spoof ARP request. 

<hr>

### NOTE: On your LINUX system before executing the ARP Spoofer, you need to enable PORT FORWARDING. (Also, you need to install scapy module on your system)
### USE THIS COMMAND TO DO THAT -->


<code> echo 1> /proc/sys/net/ipv4/ip_forward</code>


## HOW TO USE

<code>USE --help for help menu (sudo python3 arp_spoofer.py --help)</code>

## EXAMPLE COMMANDS -->

<code> sudo python3 arp_spoofer.py -t 192.168.37.2 -g 192.168.37.0 </code>
<br>
<code> sudo python3 arp_spoofer.py --target-ip 192.168.37.2 --gateway-ip 192.168.37.0 </code>
