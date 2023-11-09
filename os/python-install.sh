#!/bin/bash

set -e

sudo apt-get update
sudo apt-get install zlib1g-dev libbz2-dev libssl-dev libncurses5-dev libsqlite3-dev libreadline-dev tk-dev libgdbm-dev libdb-dev libpcap-dev xz-utils libexpat1-dev liblzma-dev libffi-dev libc6-dev


PY_VERSION=3.10.12

wget https://www.python.org/ftp/python/${PY_VERSION}/Python-${PY_VERSION}.tar.xz

tar xvf Python-${PY_VERSION}.tar.xz


cd Python-${PY_VERSION}
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