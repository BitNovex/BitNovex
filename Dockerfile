# daemon runs in the background
# run something like tail /var/log/BitNovexd/current to see the status
# be sure to run with volumes, ie:
# docker run -v $(pwd)/BitNovexd:/var/lib/BitNovexd -v $(pwd)/wallet:/home/BitNovex --rm -ti BitNovex:0.2.2
ARG base_image_version=0.10.0
FROM phusion/baseimage:$base_image_version

ADD https://github.com/just-containers/s6-overlay/releases/download/v1.21.2.2/s6-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/s6-overlay-amd64.tar.gz -C /

ADD https://github.com/just-containers/socklog-overlay/releases/download/v2.1.0-0/socklog-overlay-amd64.tar.gz /tmp/
RUN tar xzf /tmp/socklog-overlay-amd64.tar.gz -C /

ARG BITNOVEX_BRANCH=master
ENV BITNOVEX_BRANCH=${BITNOVEX_BRANCH}

# install build dependencies
# checkout the latest tag
# build and install
RUN apt-get update && \
    apt-get install -y \
      build-essential \
      python-dev \
      gcc-4.9 \
      g++-4.9 \
      git cmake \
      libboost1.58-all-dev && \
    git clone https://github.com/BitNovex/BitNovex.git /src/BitNovex && \
    cd /src/BitNovex && \
    git checkout $BITNOVEX_BRANCH && \
    mkdir build && \
    cd build && \
    cmake -DCMAKE_CXX_FLAGS="-g0 -Os -fPIC -std=gnu++11" .. && \
    make -j$(nproc) && \
    mkdir -p /usr/local/bin && \
    cp src/BitNovexd /usr/local/bin/BitNovexd && \
    cp src/walletd /usr/local/bin/walletd && \
    cp src/zedwallet /usr/local/bin/zedwallet && \
    cp src/miner /usr/local/bin/miner && \
    strip /usr/local/bin/BitNovexd && \
    strip /usr/local/bin/walletd && \
    strip /usr/local/bin/zedwallet && \
    strip /usr/local/bin/miner && \
    cd / && \
    rm -rf /src/BitNovex && \
    apt-get remove -y build-essential python-dev gcc-4.9 g++-4.9 git cmake libboost1.58-all-dev && \
    apt-get autoremove -y && \
    apt-get install -y  \
      libboost-system1.58.0 \
      libboost-filesystem1.58.0 \
      libboost-thread1.58.0 \
      libboost-date-time1.58.0 \
      libboost-chrono1.58.0 \
      libboost-regex1.58.0 \
      libboost-serialization1.58.0 \
      libboost-program-options1.58.0 \
      libicu55

# setup the BitNovexd service
RUN useradd -r -s /usr/sbin/nologin -m -d /var/lib/BitNovexd BitNovexd && \
    useradd -s /bin/bash -m -d /home/BitNovex BitNovex && \
    mkdir -p /etc/services.d/BitNovexd/log && \
    mkdir -p /var/log/BitNovexd && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/BitNovexd/run && \
    echo "fdmove -c 2 1" >> /etc/services.d/BitNovexd/run && \
    echo "cd /var/lib/BitNovexd" >> /etc/services.d/BitNovexd/run && \
    echo "export HOME /var/lib/BitNovexd" >> /etc/services.d/BitNovexd/run && \
    echo "s6-setuidgid BitNovexd /usr/local/bin/BitNovexd" >> /etc/services.d/BitNovexd/run && \
    chmod +x /etc/services.d/BitNovexd/run && \
    chown nobody:nogroup /var/log/BitNovexd && \
    echo "#!/usr/bin/execlineb" > /etc/services.d/BitNovexd/log/run && \
    echo "s6-setuidgid nobody" >> /etc/services.d/BitNovexd/log/run && \
    echo "s6-log -bp -- n20 s1000000 /var/log/BitNovexd" >> /etc/services.d/BitNovexd/log/run && \
    chmod +x /etc/services.d/BitNovexd/log/run && \
    echo "/var/lib/BitNovexd true BitNovexd 0644 0755" > /etc/fix-attrs.d/BitNovexd-home && \
    echo "/home/BitNovex true BitNovex 0644 0755" > /etc/fix-attrs.d/BitNovex-home && \
    echo "/var/log/BitNovexd true nobody 0644 0755" > /etc/fix-attrs.d/BitNovexd-logs

VOLUME ["/var/lib/BitNovexd", "/home/BitNovex","/var/log/BitNovexd"]

ENTRYPOINT ["/init"]
CMD ["/usr/bin/execlineb", "-P", "-c", "emptyenv cd /home/BitNovex export HOME /home/BitNovex s6-setuidgid BitNovex /bin/bash"]
