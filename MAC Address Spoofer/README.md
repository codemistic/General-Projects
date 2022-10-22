# MAC Address Spoofer

<pre style="color:green">
   _____      _____  _________      _____       .___  .___                                _________                     _____             
  /     \    /  _  \ \_   ___ \    /  _  \    __| _/__| _/______   ____   ______ ______  /   _____/_____   ____   _____/ ____\___________ 
 /  \ /  \  /  /_\  \/    \  \/   /  /_\  \  / __ |/ __ |\_  __ \_/ __ \ /  ___//  ___/  \_____  \\____ \ /  _ \ /  _ \   __\/ __ \_  __ \
/    Y    \/    |    \     \____ /    |    \/ /_/ / /_/ | |  | \/\  ___/ \___ \ \___ \   /        \  |_> >  <_> |  <_> )  | \  ___/|  | \/
\____|__  /\____|__  /\______  / \____|__  /\____ \____ | |__|    \___  >____  >____  > /_______  /   __/ \____/ \____/|__|  \___  >__|   
        \/         \/        \/          \/      \/    \/             \/     \/     \/          \/|__|                           \/       
 
 ~ by Abhinandan Khurana
 </pre>                                                                                                                                         
                                                                              


This is a Python based command line MAC Address Spoofer utility for LINUX systems, which takes input as an argument for the exact interface you wish to modify the MAC Address for and changes the MAC Address.



##  How to use?

<pre>
sudo python mac_changer.py --help   --> for help menu

sudo python mac_changer.py -i [INTERFACE] -m [NEW_MAC]

eg., sudo python mac_changer.py -i eth0 -m 00:11:22:33:44:55
</pre>

__________________________________________________________________________________________________________________________________________________________________________________
