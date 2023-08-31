#!/bin/bash

CODENAME=`lsb_release -c | awk '{print $2}'`

function append_str()
{
	sudo echo $1 >> /etc/apt/sources.list
	#echo $1
}

function clean_cfg()
{
	sudo echo "" > /etc/apt/sources.list
}
 
clean_cfg

append_str "# 默认注释了源码镜像以提高 apt update 速度，如有需要可自行取消注释"
append_str "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ $CODENAME main restricted universe multiverse"
append_str "# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ $CODENAME main restricted universe multiverse"
append_str "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ $CODENAME-updates main restricted universe multiverse"
append_str "# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ $CODENAME-updates main restricted universe multiverse"
append_str "deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/  $CODENAME-backports main restricted universe multiverse"
append_str "# deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ $CODENAME-backports main restricted universe multiverse"
append_str ""
append_str "# deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ $CODENAME-security main restricted universe multiverse"
append_str "# # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ $CODENAME-security main restricted universe multiverse"
append_str ""
append_str "deb http://security.ubuntu.com/ubuntu/ $CODENAME-security main restricted universe multiverse"
append_str "# deb-src http://security.ubuntu.com/ubuntu/ $CODENAME-security main restricted universe multiverse"
append_str ""
append_str "# 预发布软件源，不建议启用"
append_str "# deb https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ $CODENAME-proposed main restricted universe multiverse"
append_str "# # deb-src https://mirrors.tuna.tsinghua.edu.cn/ubuntu/ $CODENAME-proposed main restricted universe multiverse"


sudo apt-get update

