const addon = require('./build/Debug/nodeaddon.node');

var resultmsg= addon.hello();

console.log(resultmsg);

var reg=addon.setzappLaunchedRegistryKey();

console.log(reg);




