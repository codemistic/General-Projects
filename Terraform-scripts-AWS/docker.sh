#!/bin/bash
sudo yum -y update
sudo amazon-linux-extras install java-openjdk11 -y
sudo yum install docker -y
sudo systemctl start docker
sudo systemctl enable docker
sudo usermod -a -G docker ec2-user
#Make docker auto-start

sudo chkconfig docker on

# update and install docker
sudo yum install docker-ce docker-ce-cli containerd.io -y
sudo chmod 666 /var/run/docker.sock

#Because you always need it....

sudo yum install -y git
#Reboot to verify it all loads fine on its own.

#sudo reboot

#Copy the appropriate docker-compose binary from GitHub:
sudo curl -L "https://github.com/docker/compose/releases/download/1.26.0/docker-compose-$(uname -s)-$(uname -m)"  -o /usr/local/bin/docker-compose
sudo mv /usr/local/bin/docker-compose /usr/bin/docker-compose
sudo chmod +x /usr/bin/docker-compose

#sudo curl -L https://github.com/docker/compose/releases/download/1.22.0/docker-compose-$(uname -s)-$(uname -m) -o /usr/local/bin/docker-compose

#NOTE: to get the latest version (thanks @spodnet): 
#sudo curl -L https://github.com/docker/compose/releases/latest/download/docker-compose-$(uname -s)-$(uname -m) -o /usr/local/bin/docker-compose
#wget https://github.com/docker/compose/releases/latest/download/docker-compose-$(uname -s)-$(uname -m) 
#sudo mv docker-compose-$(uname -s)-$(uname -m) /usr/local/bin/docker-compose
#sudo chmod -v +x /usr/local/bin/docker-compose
#Fix permissions after download:

#sudo chmod +x /usr/local/bin/docker-compose
#Verify success:

docker-compose version

