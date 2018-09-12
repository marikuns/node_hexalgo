var addon = require('bindings')('node_hexalgo.node')
var {Buffer}=require('buffer')
module.exports.hash=(d)=>{
    var data=Buffer.from(d)
    return addon.Hash(data).toString('hex');
}
