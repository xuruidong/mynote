
set -ex

# install golang
GOLANG_VER=`go version || echo none`
if [[ $GOLANG_VER == none ]];then
    wget -q https://golang.org/dl/go1.21.3.linux-amd64.tar.gz 
    tar -C /usr/local -xzf go1.21.3.linux-amd64.tar.gz
    echo "export PATH=$PATH:/usr/local/go/bin" >> /etc/profile
    source /etc/profile
fi

# checkout 
git clone https://github.com/apache/apisix.git --depth 1 || echo "pass"

cd apisix
git config --global --add safe.directory `pwd`
git submodule update --init --recursive

rm -rf test-nginx

# free disk space
bash ./ci/free_disk_space.sh


make ci-env-up project_compose_ci=ci/pod/docker-compose.common.yml
sudo ./ci/init-common-test-service.sh || true

./ci/pod/openfunction/build-function-image.sh
make ci-env-up project_compose_ci=ci/pod/docker-compose.first.yml
make ci-env-up project_compose_ci=ci/pod/docker-compose.plugin.yml
make ci-env-up project_compose_ci=ci/pod/docker-compose.last.yml

#

./ci/linux_openresty_runner.sh before_install 


export PATH=$PATH:/usr/local/go/bin
export OPENRESTY_VERSION=default
#sudo --preserve-env=OPENRESTY_VERSION \
#./ci/linux_openresty_common_runner.sh do_install
./ci/linux_openresty_runner.sh do_install

