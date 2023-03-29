var users;

function readUsers(){
    fetch("./users.json", { mode: "no-cors" }) // desactivar CORS porque la ruta no contiene http(s)
    .then((res) => res.json())
    .then((data) => {
        users = data;
    });
}

readUsers();


function logIn(){
    var usuario_entrada = document.querySelector('#input_usuario').value;
    var contrasena_entrada = document.querySelector('#input_contrasena').value;

    var user;
    var password;
    var userFound = false; 

    if(usuario_entrada!="" && contrasena_entrada!=""){
        for(var i=0; i < users.length; i++){
            var userLocal = users[i].user;
            var passwordLocal = users[i].password;
            if(!userFound){
                if(userLocal==usuario_entrada){
                    userFound = true;
                    user = userLocal;
                    password = passwordLocal;
                }
            }
        }        
        if(userFound){
            if(usuario_entrada==user && contrasena_entrada==password){
                location.href = "main.html";
                document.getElementById('error_inicio').innerHTML = "Usuario y contraseña correctos";
            }else{
                if(contrasena_entrada!=password){
                    document.getElementById('error_inicio').innerHTML = "Contraseña incorrecta"; 
                }
            }
        }else{
            document.getElementById('error_inicio').innerHTML = "Usuario no encontrado"; 
        }
    }else{
        if(contrasena_entrada==""){
            document.getElementById('error_inicio').innerHTML = "No ingresó contraseña. Ingrese una e inténtelo de nuevo";
        }
        if(usuario_entrada==""){
            document.getElementById('error_inicio').innerHTML = "No ingresó usuario. Ingrese uno e inténtelo de nuevo";
        }
    }

}