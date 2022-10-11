variable "vpc_cidr" {}
variable "vpc_name" {}
variable "IGW_name" {}
variable "instance_name" {}
variable "key_name" {}
variable "public_subnet1_cidr" {}
#variable "public_subnet2_cidr" {}
#variable "public_subnet3_cidr" {}
variable "private_subnet1_cidr" {}
variable "public_subnet1_name" {}
#variable "public_subnet2_name" {}
#variable "public_subnet3_name" {}
variable "private_subnet1_name" {}
variable "Main_Routing_Table" {}
variable "azs" { default = "ap-northeast-1a" }
#"us-east-1b", "us-east-1c"]
variable "environment" { default = "dev" }
variable "instance_type" { default = "t2.medium" }
variable "instance_type1" { default = "t2.xlarge" }

# test = "t2.micro"
#prod = "t2.medium"

variable "sg_name" {}
