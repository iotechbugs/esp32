deps_config := \
	/Users/sankar/esp/esp-mdf/esp-idf/components/app_trace/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/aws_iot/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/bt/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/driver/Kconfig \
	/Users/sankar/esp/esp-mdf/components/third_party/esp-aliyun/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/esp32/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/esp_adc_cal/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/esp_event/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/esp_http_client/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/esp_http_server/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/ethernet/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/fatfs/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/freemodbus/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/freertos/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/heap/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/libsodium/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/log/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/lwip/Kconfig \
	/Users/sankar/esp/esp-mdf/components/maliyun_linkkit/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/mbedtls/Kconfig \
	/Users/sankar/esp/esp-mdf/components/mcommon/Kconfig \
	/Users/sankar/esp/esp-mdf/components/mconfig/Kconfig \
	/Users/sankar/esp/esp-mdf/components/mdebug/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/mdns/Kconfig \
	/Users/sankar/esp/esp-mdf/components/mespnow/Kconfig \
	/Users/sankar/esp/esp-mdf/components/third_party/miniz/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/mqtt/Kconfig \
	/Users/sankar/esp/esp-mdf/components/mupgrade/Kconfig \
	/Users/sankar/esp/esp-mdf/components/mwifi/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/nvs_flash/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/openssl/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/pthread/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/spi_flash/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/spiffs/Kconfig \
	/Users/sankar/esp/esp-mdf/components/third_party/esp-aliyun/components/ssl/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/tcpip_adapter/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/vfs/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/wear_levelling/Kconfig \
	/Users/sankar/esp/esp-mdf/esp-idf/components/bootloader/Kconfig.projbuild \
	/Users/sankar/esp/esp-mdf/esp-idf/components/esptool_py/Kconfig.projbuild \
	/Users/sankar/Documents/iotechbugs/code-base/root/main/Kconfig.projbuild \
	/Users/sankar/esp/esp-mdf/esp-idf/components/partition_table/Kconfig.projbuild \
	/Users/sankar/esp/esp-mdf/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)

ifneq "$(IDF_CMAKE)" "n"
include/config/auto.conf: FORCE
endif

$(deps_config): ;
