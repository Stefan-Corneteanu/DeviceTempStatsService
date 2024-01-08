DEVICE_PACKAGE_OVERLAYS += device/stefan/overlays
BOARD_SEPOLICY_DIRS += device/stefan/sepolicy \
					   device/stefan/sepolicy/devicetempstats_service

PRODUCT_PACKAGES += devicetempstats_service

HAL_MANIFEST += device/stefan/manifests/manifest.xml

DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE += device/stefan/manifests/Framework_compatibility_matrix.xml