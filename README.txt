DYApi SDK Version 2.6.1

Don't forget to add this script in the "build phases"
DY_FRAMEWORK_PATH="${BUILT_PRODUCTS_DIR}/${FRAMEWORKS_FOLDER_PATH}/DYSDK.framework/DYSDK"
echo "Removing Unnecessary architectures from DYSDK framework"
lipo -remove i386 -remove x86_64 $DY_FRAMEWORK_PATH -output $DY_FRAMEWORK_PATH 
