
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
    filePreload0.open('GET', 'app.icf', true);
    filePreload0.responseType = 'arraybuffer';
    filePreload0.onload = function() {
      var arrayBuffer = filePreload0.response;
      assert(arrayBuffer, 'Loading file app.icf failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/', 'app.icf', byteArray, true, true, function() {
        Module['removeRunDependency']('fp app.icf');

      });
    };
    Module['addRunDependency']('fp app.icf');
    filePreload0.send(null);

    var filePreload1 = new DataRequest();
    filePreload1.open('GET', 'CloseNormal.png', true);
    filePreload1.responseType = 'arraybuffer';
    filePreload1.onload = function() {
      var arrayBuffer = filePreload1.response;
      assert(arrayBuffer, 'Loading file CloseNormal.png failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/', 'CloseNormal.png', byteArray, true, true, function() {
        Module['removeRunDependency']('fp CloseNormal.png');

      });
    };
    Module['addRunDependency']('fp CloseNormal.png');
    filePreload1.send(null);

    var filePreload2 = new DataRequest();
    filePreload2.open('GET', 'CloseSelected.png', true);
    filePreload2.responseType = 'arraybuffer';
    filePreload2.onload = function() {
      var arrayBuffer = filePreload2.response;
      assert(arrayBuffer, 'Loading file CloseSelected.png failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/', 'CloseSelected.png', byteArray, true, true, function() {
        Module['removeRunDependency']('fp CloseSelected.png');

      });
    };
    Module['addRunDependency']('fp CloseSelected.png');
    filePreload2.send(null);

    var filePreload3 = new DataRequest();
    filePreload3.open('GET', 'Player.png', true);
    filePreload3.responseType = 'arraybuffer';
    filePreload3.onload = function() {
      var arrayBuffer = filePreload3.response;
      assert(arrayBuffer, 'Loading file Player.png failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/', 'Player.png', byteArray, true, true, function() {
        Module['removeRunDependency']('fp Player.png');

      });
    };
    Module['addRunDependency']('fp Player.png');
    filePreload3.send(null);

    var filePreload4 = new DataRequest();
    filePreload4.open('GET', 'Projectile.png', true);
    filePreload4.responseType = 'arraybuffer';
    filePreload4.onload = function() {
      var arrayBuffer = filePreload4.response;
      assert(arrayBuffer, 'Loading file Projectile.png failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/', 'Projectile.png', byteArray, true, true, function() {
        Module['removeRunDependency']('fp Projectile.png');

      });
    };
    Module['addRunDependency']('fp Projectile.png');
    filePreload4.send(null);

    var filePreload5 = new DataRequest();
    filePreload5.open('GET', 'Target.png', true);
    filePreload5.responseType = 'arraybuffer';
    filePreload5.onload = function() {
      var arrayBuffer = filePreload5.response;
      assert(arrayBuffer, 'Loading file Target.png failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/', 'Target.png', byteArray, true, true, function() {
        Module['removeRunDependency']('fp Target.png');

      });
    };
    Module['addRunDependency']('fp Target.png');
    filePreload5.send(null);

    var filePreload6 = new DataRequest();
    filePreload6.open('GET', 'app.config.txt', true);
    filePreload6.responseType = 'arraybuffer';
    filePreload6.onload = function() {
      var arrayBuffer = filePreload6.response;
      assert(arrayBuffer, 'Loading file app.config.txt failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/', 'app.config.txt', byteArray, true, true, function() {
        Module['removeRunDependency']('fp app.config.txt');

      });
    };
    Module['addRunDependency']('fp app.config.txt');
    filePreload6.send(null);

    var filePreload7 = new DataRequest();
    filePreload7.open('GET', 'background-music-aac.wav', true);
    filePreload7.responseType = 'arraybuffer';
    filePreload7.onload = function() {
      var arrayBuffer = filePreload7.response;
      assert(arrayBuffer, 'Loading file background-music-aac.wav failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/', 'background-music-aac.wav', byteArray, true, true, function() {
        Module['removeRunDependency']('fp background-music-aac.wav');

      }, function() { Module['removeRunDependency']('fp background-music-aac.wav') });
    };
    Module['addRunDependency']('fp background-music-aac.wav');
    filePreload7.send(null);

    var filePreload8 = new DataRequest();
    filePreload8.open('GET', 'development.icf', true);
    filePreload8.responseType = 'arraybuffer';
    filePreload8.onload = function() {
      var arrayBuffer = filePreload8.response;
      assert(arrayBuffer, 'Loading file development.icf failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/', 'development.icf', byteArray, true, true, function() {
        Module['removeRunDependency']('fp development.icf');

      });
    };
    Module['addRunDependency']('fp development.icf');
    filePreload8.send(null);

    var filePreload9 = new DataRequest();
    filePreload9.open('GET', 'pew-pew-lei.wav', true);
    filePreload9.responseType = 'arraybuffer';
    filePreload9.onload = function() {
      var arrayBuffer = filePreload9.response;
      assert(arrayBuffer, 'Loading file pew-pew-lei.wav failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/', 'pew-pew-lei.wav', byteArray, true, true, function() {
        Module['removeRunDependency']('fp pew-pew-lei.wav');

      }, function() { Module['removeRunDependency']('fp pew-pew-lei.wav') });
    };
    Module['addRunDependency']('fp pew-pew-lei.wav');
    filePreload9.send(null);

    var filePreload10 = new DataRequest();
    filePreload10.open('GET', 'fonts/arial.ttf', true);
    filePreload10.responseType = 'arraybuffer';
    filePreload10.onload = function() {
      var arrayBuffer = filePreload10.response;
      assert(arrayBuffer, 'Loading file fonts/arial.ttf failed.');
      var byteArray = !arrayBuffer.subarray ? new Uint8Array(arrayBuffer) : arrayBuffer;
      
      Module['FS_createPreloadedFile']('/fonts', 'arial.ttf', byteArray, true, true, function() {
        Module['removeRunDependency']('fp fonts/arial.ttf');

      });
    };
    Module['addRunDependency']('fp fonts/arial.ttf');
    filePreload10.send(null);

    if (!Module.expectedDataFileDownloads) {
      Module.expectedDataFileDownloads = 0;
      Module.finishedDataFileDownloads = 0;
    }
    Module.expectedDataFileDownloads++;

    var PACKAGE_PATH = window['encodeURIComponent'](window.location.pathname.toString().substring(0, window.location.pathname.toString().lastIndexOf('/')) + '/');
    var PACKAGE_NAME = 'SimpleGame.data';
    var REMOTE_PACKAGE_NAME = 'SimpleGame.data';
    var PACKAGE_UUID = '3c118ec7-5ea7-40e3-9221-020c4cf81588';
  
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
      
        curr = DataRequest.prototype.requests['app.icf'];
        curr.response = byteArray.subarray(0,640);
        curr.onload();
      
        curr = DataRequest.prototype.requests['CloseNormal.png'];
        curr.response = byteArray.subarray(640,6951);
        curr.onload();
      
        curr = DataRequest.prototype.requests['CloseSelected.png'];
        curr.response = byteArray.subarray(6951,12450);
        curr.onload();
      
        curr = DataRequest.prototype.requests['Player.png'];
        curr.response = byteArray.subarray(12450,16779);
        curr.onload();
      
        curr = DataRequest.prototype.requests['Projectile.png'];
        curr.response = byteArray.subarray(16779,21362);
        curr.onload();
      
        curr = DataRequest.prototype.requests['Target.png'];
        curr.response = byteArray.subarray(21362,26591);
        curr.onload();
      
        curr = DataRequest.prototype.requests['app.config.txt'];
        curr.response = byteArray.subarray(26591,26882);
        curr.onload();
      
        curr = DataRequest.prototype.requests['background-music-aac.wav'];
        curr.response = byteArray.subarray(26882,1671982);
        curr.onload();
      
        curr = DataRequest.prototype.requests['development.icf'];
        curr.response = byteArray.subarray(1671982,1685209);
        curr.onload();
      
        curr = DataRequest.prototype.requests['pew-pew-lei.wav'];
        curr.response = byteArray.subarray(1685209,1734661);
        curr.onload();
      
        curr = DataRequest.prototype.requests['fonts/arial.ttf'];
        curr.response = byteArray.subarray(1734661,2507897);
        curr.onload();
                Module['removeRunDependency']('datafile_SimpleGame.data');

    };
    Module['addRunDependency']('datafile_SimpleGame.data');

    function handleError(error) {
      console.error('package error:', error);
    };
  
    if (!Module.preloadResults)
      Module.preloadResults = {};
  
      Module.preloadResults[PACKAGE_NAME] = {fromCache: false};
      fetchRemotePackage(REMOTE_PACKAGE_NAME, processPackageData, handleError);
      });

})();

