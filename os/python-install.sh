#!/bin/bash

set -ex

function install_dep_on_ubuntu()
{
	sudo apt-get update
	sudo apt-get install zlib1g-dev libbz2-dev libssl-dev libncurses5-dev libsqlite3-dev libreadline-dev tk-dev libgdbm-dev libdb-dev libpcap-dev xz-utils libexpat1-dev liblzma-dev libffi-dev libc6-dev
}

function install_dep_on_centos7()
{
	yum -y install zlib zlib-devel libffi libffi-devel

	yum -y install readline-devel
	
	yum -y install openssl-devel openssl11 openssl11-devel
	#安装openssl11，后期的pip3安装网络相关模块需要用到ssl模块。
	export CFLAGS=$(pkg-config --cflags openssl11)
	export LDFLAGS=$(pkg-config --libs openssl11)
}

function install_dep()
{
	NAME=`cat /etc/*-release | grep -w "NAME="`

	DIST_NAME=${NAME#*=}

	set +e
	res=`echo $NAME | grep CentOS`
	if [[ $res != "" ]]
	then
	    echo "centos"
	 	install_dep_on_centos7
	fi
	
	res=`echo $NAME | grep Ubuntu`
	if [[ $res != "" ]]
	then
	    echo "Ubuntu"
	 	install_dep_on_ubuntu
	fi

	set -e
}

function patch_configure()
{
	NAME=`cat /etc/*-release | grep -w "NAME="`

	DIST_NAME=${NAME#*=}

	set +e
	res=`echo $NAME | grep CentOS`
	if [[ $res != "" ]]
	then
	    echo "modify 'configure' for enable ssl module on centos 7"
	 	sed -i 's/PKG_CONFIG openssl /PKG_CONFIG openssl11 /g' configure
	fi
	
	res=`echo $NAME | grep Ubuntu`
	if [[ $res != "" ]]
	then
		echo ""
	fi

	set -e
}
#install_dep

PY_VERSION=3.12.0

if [ -f "Python-${PY_VERSION}.tar.xz" ];then
	PY_SRC_PKG="Python-${PY_VERSION}.tar.xz"
elif [ -f "Python-${PY_VERSION}.tgz" ];then
	PY_SRC_PKG="Python-${PY_VERSION}.tgz"
else
	wget https://www.python.org/ftp/python/${PY_VERSION}/Python-${PY_VERSION}.tar.xz
	PY_SRC_PKG="Python-${PY_VERSION}.tar.xz"
fi

rm -rf Python-${PY_VERSION}

tar xvf ${PY_SRC_PKG}


cd Python-${PY_VERSION}

patch_configure

./configure --prefix=/usr/local/Python${PY_VERSION} --enable-optimizations
#./configure --prefix=/usr/local/Python${PY_VERSION}

make -j
sudo make install


function set_index_url()
{
	mkdir -p $HOME/.config/pip
	PIP_CONF=$HOME/.config/pip/pip.conf
	echo "[global]" > PIP_CONF
	echo "index-url = https://mirrors.aliyun.com/pypi/simple/" >> PIP_CONF
	echo "[install]" >> PIP_CONF
	echo "trusted-host = mirrors.aliyun.com" >> PIP_CONF
}
