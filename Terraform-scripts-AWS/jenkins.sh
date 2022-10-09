#!/bin/bash

sudo yum update -y
sudo yum install -y git
sudo wget -O /etc/yum.repos.d/jenkins.repo \
    https://pkg.jenkins.io/redhat-stable/jenkins.repo
sudo rpm --import https://pkg.jenkins.io/redhat-stable/jenkins.io.key
#sudo rpm --import https://jenkins-ci.org/redhat/jenkins-ci.org.key
sudo yum upgrade -y
sudo yum install jenkins -y
sudo amazon-linux-extras install java-openjdk11 -y
sudo systemctl daemon-reload
sudo systemctl start jenkins
sudo systemctl enable jenkins
sudo systemctl status jenkins
sudo cat /var/lib/jenkins/secrets/initialAdminPassword
sudo wget https://dl.fedoraproject.org/pub/epel/epel-release-latest-7.noarch.rpm
sudo yum install epel-release-latest-7.noarch.rpm
sudo yum update -y
sudo yum install python python-devel python-pip openssl ansible -y
sudo amazon-linux-extras install ansible2
# sudo ansible --version
