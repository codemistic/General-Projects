# infra-terraform-scripts
FOR CREATING COMPLETE INFRASTRUCTURE USING AWS CLOUD PROVIDER, CREATING CUSTOM VPC, SG, EC2, SUBNETS, ROUTE, etc 
USING TERRAFORM
#Run these terraform scripts in your machine only after SETTING the aws configuration credentials like key and password

===DOWNLOAD TERRAFORM ON EC2-LINUX==========================================================================

sudo yum install -y yum-utils
sudo yum-config-manager --add-repo https://rpm.releases.hashicorp.com/AmazonLinux/hashicorp.repo
sudo yum -y install terraform

============AWS CLI==========================================================================================

curl "https://awscli.amazonaws.com/awscli-exe-linux-x86_64.zip" -o "awscliv2.zip"
unzip awscliv2.zip
sudo ./aws/install

=================AWS-CONFIG==================================================================================

aws config


==========INSTALL-GIT========================================================================================

yum install git -y

git clone REPOSITORY_NAME

NOW AFTER CLONING THIS REPOSITORY, RUN THE TERRAFORM SCRIPTS BY DOING TERRAFORM INIT AND TERRAFORM APPLY

ec2.tf, vpc.tf, route.tf, subnet.tf, sg.tf , prvt_sub.tf




