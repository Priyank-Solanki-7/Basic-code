let getInput =(value) => {
  document.querySelector ('#result').value += value;
};
let calculate = () => {
  try {
    let ans = eval (document.querySelector ('#result').value);
    document.querySelector ('#result').value = ans;
  } catch (error) {
    document.querySelector ('#result').value = 'error';
  }
};
let clearall = () => {
    document.querySelector('#result').value="";
};
