#!/usr/bin/ruby
require 'fileutils'
#require 'ftools'

def moveMK()
    dirto = '../proj.android/jni'
    
    fileFrom = './Android.mk'
    fileTo = dirto + '/' + 'Android.mk';
    
    FileUtils.cp(fileFrom,fileTo)
    
end




$f = File.open( 'Android.mk', 'w' )


puts 'I WORK'

def searchFile(dirmane)
	Dir.foreach(dirmane) do |entry|
   		
   		if  entry != '.' && entry != '..' && entry != '.svn' then
		    if File.directory?(dirmane+'/'+entry) == true then
		        searchFile(dirmane+'/'+entry)
                elsif File.extname(dirmane+'/'+entry) == '.cpp' || File.extname(dirmane+'/'+entry) == '.c' || File.extname(dirmane+'/'+entry) == '.cc' then
   				
                if File.fnmatch('./onlyplay_lib/platforms/ios', dirmane) == false then
                    $f.puts '../../Classes/'+dirmane+'/'+entry + '\\'
                end
                
            end
	    end
   		
	end
end

def searchInclude(dirmane)
	Dir.foreach(dirmane) do |entry|
        
		if  entry != '.' && entry != '..' && entry != '.svn' then
			if File.fnmatch('./onlyplay_lib/platforms/ios', dirmane+'/'+entry) == false  then
                if File.directory?(dirmane+'/'+entry) == true then
                    searchInclude(dirmane+'/'+entry)
                    $f.puts 'LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../Classes/'+dirmane+'/'+entry
                end
			end
		end
        
	    
	end
end

$f.puts 'LOCAL_PATH := $(call my-dir)'

$f.puts 'include $(CLEAR_VARS)'

$f.puts 'LOCAL_MODULE := thingslocation_shared'

$f.puts'LOCAL_MODULE_FILENAME := libthingslocation'

$f.puts 'LOCAL_SRC_FILES := hellocpp/main.cpp\\'

searchFile('.')


$f.print "\\\n"

$f.puts 'LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes'
searchInclude('.')

$f.puts 'LOCAL_C_INCLUDES += $(LOCAL_PATH)/../../../../cocos2dx/platform/'


$f.puts 'LOCAL_LDLIBS := $(NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi-v7a/libsupc++.a'
$f.puts 'LOCAL_LDLIBS += $(NDK_ROOT)/sources/cxx-stl/gnu-libstdc++/4.6/libs/armeabi-v7a/libgnustl_static.a'


$f.puts 'LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static'
$f.puts 'LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static'
$f.puts 'LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static'
$f.puts 'LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static'
$f.puts 'LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static'

$f.puts 'include $(BUILD_SHARED_LIBRARY)'

$f.puts '$(call import-module,cocos2dx)'
$f.puts '$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)'
$f.puts '$(call import-module,CocosDenshion/android)'
$f.puts '$(call import-module,extensions)'
$f.puts '$(call import-module,external/Box2D)'
$f.puts '$(call import-module,external/chipmunk)'

$f.close



moveMK()
