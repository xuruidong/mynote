
## 编译

## 配置
### sysconfig.xml

```
<CONFIG>
    <BASECONFIG>
        <AGENT_MODEL value="2" />
        <UDPPORT value="10001" />
        <PASSWORD write="private" read="public" />
        <RSPTDOMAIN value="127.0.0.1"/>
		<NETCARD_NAME prefix="eth" />
        <HOSTBASE>
            <WATCH_PORT>
                <NODE type="1" name="bt" port="6543" num="2" />
                <NODE type="2" name="http" port="6544" num="2" />
                <NODE type="3" name="em" port="6546" num="1" />
                <NODE type="4" name="xl" port="6547" num="2" />
                <NODE type="5" name="wireless" port="6548" num="3" />
                <NODE type="6" name="ppstream" port="6549" num="2" />
                <NODE type="7" name="web" port="6545" num="1" />
                <NODE type="8" name="pplive" port="6545" num="1" />
                <NODE type="9" name="qvod" port="6545" num="1" />
                <NODE type="10" name="pps" port="6545" num="1" />
                <NODE type="11" name="dns" port="6545" num="1" />
                <NODE type="12" name="qqlive" port="6555" num="1" />
                <NODE type="17" name="bfppc" port="6556" num="1" />
                <NODE type="20" name="funshion" port="6557" num="1" />
                <NODE type="21" name="iqiyi" port="6566" num="1" />
                <NODE type="22" name="kugou" port="6567" num="1" />
            </WATCH_PORT>
            <!--unit:GB-->
            <DISK_MIN_SIZE value="20" />
            <DISK_MOUNT_PATH>
                <NODE path="/home" />
            </DISK_MOUNT_PATH>
            <!--network interface infomation-->
            <INTERFACE>
                <NODE name="eth1" />
            </INTERFACE>
            <TRAP>
                <!--value:open or close-->
                <LOG_SWITCH value="open" />
                <HOST ip="10.0.3.102" />
                <PORT value="162" />
                <!--unit:KB-->
                <MEMORYUSAGE value="2" warning_valve="100" />
                <CPUUSAGE value="100" />
                <!--unit:mps-->
                <NETFLOWOUT value="1" value2="1000" />
                <NETFLOWIN value="2" value2="10000" />
                <DISK_WARNING_VALVE value="95" />
            </TRAP>
        </HOSTBASE>
    </BASECONFIG>
    <CACHEBASE>
        <SYSCONFIG>
            <PPM addr="10.0.3.16" />
            <CAS addr="10.0.3.16" />
            <LOGTABLE>
                <NODE addr="10.0.3.16" />
            </LOGTABLE>
            <WSTABLE />
            <PPSTABLE>
                <NODE addr="10.0.3.102" />
            </PPSTABLE>
        </SYSCONFIG>
        <CLIENTPOOL>
			<GROUP id="0">
				<NODE startaddr="10.0.3.234" endaddr="10.0.3.234" proxy="-1" type="1" />
				<NODE startaddr="10.0.3.200" endaddr="10.0.3.200" type="1" />
				<NODE startaddr="10.0.3.127" endaddr="10.0.3.127" type="1" />
				<NODE startaddr="10.0.3.251" endaddr="10.0.3.251" type="1" />
				<NODE startaddr="10.0.3.240" endaddr="10.0.3.240" type="1" />
				<NODE startaddr="10.0.3.204" endaddr="10.0.3.204" type="1" />
				<NODE startaddr="10.0.3.66" endaddr="10.0.3.66" type="1" />
			</GROUP>
        </CLIENTPOOL>
        <FREEDSTADDR table_type="0">
            <!--NODE startaddr="100.0.0.1" endaddr="124.255.255.254" startport="80" endport="82" /-->
            <!--NODE startaddr="200.0.0.1" endaddr="220.255.255.254" startport="80" endport="82" /-->
            <!--NODE startaddr="60.0.0.1" endaddr="60.255.255.254" startport="80" endport="82" /-->
            <NODE startaddr="124.193.226.240" endaddr="124.193.226.241" startport="80" endport="82" />
        </FREEDSTADDR>
		<DPDKCONFIG>
                <EALPARAM>
                        <COREMASK value="ff" />    
                        <MEMCHANNELNUM value="4" />
                        <PORTMASK value="0f" /> 
                        <RX_RINGS_SIZE value="512" />  
                </EALPARAM>
        </DPDKCONFIG>
        <PPSCONFIG>
            <NODE index="1" name="eth2" direct="2" portdesc="eth2" />
        </PPSCONFIG>
        <LOGSAVEDAYS value="20" />
        <LOGRECORDS value="56987" />
    </CACHEBASE>
    <NETADDRCONF>
        <NETRANGE>
            <NODE startaddr="10.0.3.1" endaddr="10.0.3.255" />
        </NETRANGE>
    </NETADDRCONF>
</CONFIG>
```

* FREEDSTADDR  需要放行的目的地址，

### pps_config.xml

* CLIENTPOOL_CHECK_DIRECT value="0"  0 src_addr, 1 dst_addr ,2 all_addr
* MODULE_CLIENTPOOL_USE_FLAG value="0" 受否对模块进行clientpool 匹配 