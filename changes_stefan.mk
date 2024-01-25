BOARD_SEPOLICY_DIRS += device/stefan/sepolicy \
					   device/stefan/sepolicy/devicetempstats_service

PRODUCT_PACKAGES += devicetempstats_service

DEVICE_MANIFEST_FILE += device/stefan/manifests/manifest.xml
DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE += device/stefan/manifests/framework_compatibility_matrix.xml