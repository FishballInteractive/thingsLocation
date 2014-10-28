
(function() {

  if (typeof Module == 'undefined') Module = {};
  if (!Module['preRun']) Module['preRun'] = [];
  Module["preRun"].push(function() {

function assert(check, msg) {
  if (!check) throw msg + new Error().stack;
}
Module['FS_createPath']('/', 'fonts', true, true);

    function DataRequest() {}
    DataRequest.prototype = {
      requests: {},
      open: function(mode, name) {
        this.requests[name] = this;
      },
      send: function() {}
    };
  
    var filePreload0 = new DataRequest();
    filePreload0.open('GET', 'CloseNormal.png', true);
    filePreload0.responseType = 'arraybuffer';
    filePreload0.onload = function() {
      var arrayBuffer = filePreload0.response;
      assert(arrayBuffer, 'Loading file CloseNormal.png failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/', 'CloseNormal.png', byteArray, true, true, function() {
        Module['removeRunDependency']('fp CloseNormal.png');

      });
    };
    Module['addRunDependency']('fp CloseNormal.png');
    filePreload0.send(null);

    var filePreload1 = new DataRequest();
    filePreload1.open('GET', 'CloseSelected.png', true);
    filePreload1.responseType = 'arraybuffer';
    filePreload1.onload = function() {
      var arrayBuffer = filePreload1.response;
      assert(arrayBuffer, 'Loading file CloseSelected.png failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/', 'CloseSelected.png', byteArray, true, true, function() {
        Module['removeRunDependency']('fp CloseSelected.png');

      });
    };
    Module['addRunDependency']('fp CloseSelected.png');
    filePreload1.send(null);

    var filePreload2 = new DataRequest();
    filePreload2.open('GET', 'HelloWorld.png', true);
    filePreload2.responseType = 'arraybuffer';
    filePreload2.onload = function() {
      var arrayBuffer = filePreload2.response;
      assert(arrayBuffer, 'Loading file HelloWorld.png failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/', 'HelloWorld.png', byteArray, true, true, function() {
        Module['removeRunDependency']('fp HelloWorld.png');

      });
    };
    Module['addRunDependency']('fp HelloWorld.png');
    filePreload2.send(null);

    var filePreload3 = new DataRequest();
    filePreload3.open('GET', 'fonts/arial.ttf', true);
    filePreload3.responseType = 'arraybuffer';
    filePreload3.onload = function() {
      var arrayBuffer = filePreload3.response;
      assert(arrayBuffer, 'Loading file fonts/arial.ttf failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/fonts', 'arial.ttf', byteArray, true, true, function() {
        Module['removeRunDependency']('fp fonts/arial.ttf');

      });
    };
    Module['addRunDependency']('fp fonts/arial.ttf');
    filePreload3.send(null);

    var filePreload4 = new DataRequest();
    filePreload4.open('GET', 'fonts/Marker Felt.ttf', true);
    filePreload4.responseType = 'arraybuffer';
    filePreload4.onload = function() {
      var arrayBuffer = filePreload4.response;
      assert(arrayBuffer, 'Loading file fonts/Marker Felt.ttf failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/fonts', 'Marker Felt.ttf', byteArray, true, true, function() {
        Module['removeRunDependency']('fp fonts/Marker Felt.ttf');

      });
    };
    Module['addRunDependency']('fp fonts/Marker Felt.ttf');
    filePreload4.send(null);

    if (!Module.expectedDataFileDownloads) {
      Module.expectedDataFileDownloads = 0;
      Module.finishedDataFileDownloads = 0;
    }
    Module.expectedDataFileDownloads++;

    var PACKAGE_PATH = window['encodeURIComponent'](window.location.pathname.toString().substring(0, window.location.pathname.toString().lastIndexOf('/')) + '/');
    var PACKAGE_NAME = 'HelloCpp.data';
    var REMOTE_PACKAGE_NAME = 'HelloCpp.data';
    var PACKAGE_UUID = 'e8135971-6a81-41a3-b617-485cd64818c4';
  
    function fetchRemotePackage(packageName, callback, errback) {
      var xhr = new XMLHttpRequest();
      xhr.open('GET', packageName, true);
      xhr.responseType = 'arraybuffer';
      xhr.onprogress = function(event) {
        var url = packageName;
        if (event.loaded && event.total) {
          if (!xhr.addedTotal) {
            xhr.addedTotal = true;
            if (!Module.dataFileDownloads) Module.dataFileDownloads = {};
            Module.dataFileDownloads[url] = {
              loaded: event.loaded,
              total: event.total
            };
          } else {
            Module.dataFileDownloads[url].loaded = event.loaded;
          }
          var total = 0;
          var loaded = 0;
          var num = 0;
          for (var download in Module.dataFileDownloads) {
          var data = Module.dataFileDownloads[download];
            total += data.total;
            loaded += data.loaded;
            num++;
          }
          total = Math.ceil(total * Module.expectedDataFileDownloads/num);
          Module['setStatus']('Downloading data... (' + loaded + '/' + total + ')');
        } else if (!Module.dataFileDownloads) {
          Module['setStatus']('Downloading data...');
        }
      };
      xhr.onload = function(event) {
        var packageData = xhr.response;
        callback(packageData);
      };
      xhr.send(null);
    };

    function processPackageData(arrayBuffer) {
      Module.finishedDataFileDownloads++;
      assert(arrayBuffer, 'Loading data file failed.');
      var byteArray = new Uint8Array(arrayBuffer);
      var curr;
      
        curr = DataRequest.prototype.requests['CloseNormal.png'];
        curr.response = byteArray.subarray(0,6835);
        curr.onload();
      
        curr = DataRequest.prototype.requests['CloseSelected.png'];
        curr.response = byteArray.subarray(6835,12546);
        curr.onload();
      
        curr = DataRequest.prototype.requests['HelloWorld.png'];
        curr.response = byteArray.subarray(12546,172669);
        curr.onload();
      
        curr = DataRequest.prototype.requests['fonts/arial.ttf'];
        curr.response = byteArray.subarray(172669,945905);
        curr.onload();
      
        curr = DataRequest.prototype.requests['fonts/Marker Felt.ttf'];
        curr.response = byteArray.subarray(945905,971681);
        curr.onload();
                Module['removeRunDependency']('datafile_HelloCpp.data');

    };
    Module['addRunDependency']('datafile_HelloCpp.data');

    function handleError(error) {
      console.error('package error:', error);
    };
  
    if (!Module.preloadResults)
      Module.preloadResults = {};
  
      Module.preloadResults[PACKAGE_NAME] = {fromCache: false};
      fetchRemotePackage(REMOTE_PACKAGE_NAME, processPackageData, handleError);
      });

})();

