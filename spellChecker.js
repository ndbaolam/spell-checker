const fs = require('fs').promises;

const spellCheck = (x, y) => {
  const f = Array.from({ length: x.length + 1 }, 
    () => Array(y.length + 1).fill(0));

  for(let i = 0; i <= x.length; i++){
    for(let j = 0; j <= y.length; j++){
      if(i === 0) f[i][j] = j;
			else if(j === 0) f[i][j] = i;
			else {
				if(x[i-1] === y[j-1])
					f[i][j] = f[i-1][j-1];
				else
					f[i][j] = Math.min(f[i-1][j], f[i-1][j-1], f[i][j-1]) + 1;
			}
    }
  }
  return f[x.length][y.length];
}

fs.readFile('./words.txt', 'utf8')
.then(data => data.toString().split('\r\n'))
.then(words => {
  for(let i = 0; i < 5; i++){
    console.log(words[i], spellCheck("lam", words[i]));
  }
});