const https = require('https');
const fs = require('fs');

const options = {
  key: fs.readFileSync('./2043129_huyuanrui.top.key'),
  cert: fs.readFileSync('./2043129_huyuanrui.top.pem')
};

https.createServer(options, (req, res) => {
  res.writeHead(200);
  res.end('hello world\n');
}).listen(8000);