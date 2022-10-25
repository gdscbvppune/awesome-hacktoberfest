const chatform = document.getElementById(' ');

const socket = io();

//message from server
socket.io('message', message => {
  console.log(message);
  outputmessage(message);
});

//Message submit//
chatform.addEventListener('submit',(e) =>{
  e.preventDefault();

//get message text
  const msg  = e.target.elements.msg.value;
//Emit messageto server
  socket.emit('chatmessage',msg);
});
//output message to dom
function outputmessage(message){
  const div = document.createElement('div');
  div.classList.add('message');
  div.innerHTML ='	<p class="meta">Deepak <span>9:12pm</span></p>
    <p class="text">
    anyone up?
    </p>
  </div>
  <div class="message">
    <p class="meta">Abinash <span>9:15pm</span></p>
    <p class="text">
    ${message}
    </p>';
    document.querySelector('.chat-messages').appendchild(div);
}
