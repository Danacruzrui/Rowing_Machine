// window.addEventListener('resize', onWindowResize, false);

//Crear gráficos
let myChart, myChart2, myChart3;

function initGraphs(){
    var array_length = 10;
    var xValues = [];
    // var xValues = [1,2,3,4,5,6,7,8,9,0];
    for (let i = 0; i < array_length; i++) {
      xValues[i] = i;
    }
  
    // var yValues = [1,2,3,4,5,6,7,8,9,0]; /*valores que se representan en la gráfica*/
    var yValues = [];
  
    myChart = new Chart(document.getElementById("myChart"), {
      type: "line",
      data: {
        labels: [],
        datasets: [{
          fill: false,
          lineTension: 0.5,
          backgroundColor: "rgba(0,18,51,1.0)",
          borderColor: "rgba(255,255,255,0.8)",
          data:[]
        }]
      },
      options: {
        legend: {display: false},
        scales: {
          yAxes: [{
            ticks: {
              min: 0,
              max:170,
              fontColor: "rgba(0,0,0,1.0)"
            },
            scaleLabel:{
              display: true,
              labelString: 'Velocidad (rpm)',
              fontColor: "rgba(0,0,0,1.0)",
              fontSize: 16
            },
            gridLines: {
              display: true,
              color: "rgba(0,0,0,1.0)"
            }
          }],
          xAxes: [{
            ticks: {
              fontColor: "rgba(0,0,0,1.0)"
            },
            scaleLabel:{
              display: true,
              labelString: 'Tiempo (s)',
              fontColor: "rgba(0,0,0,1.0)",
              fontSize: 16
            },
            gridLines: {
              display: true,
              color: "rgba(0,0,0,1.0)"
            }
          }],
        }
      }
    });

    myChart2 = new Chart(document.getElementById("myChart2"), {
      type: "line",
      data: {
        labels: [],
        datasets: [{
          fill: false,
          lineTension: 0.5,
          backgroundColor: "rgba(0,18,51,1.0)",
          borderColor: "rgba(255,255,255,0.8)",
          data: []
        }]
      },
      options: {
        legend: {display: false},
        scales: {
          yAxes: [{
            ticks: {
              min: -1, 
              max:66,
              fontColor: "rgba(0,0,0,1.0)"
            },
            scaleLabel:{
              display: true,
              labelString: 'Posición (cm)',
              fontColor: "rgba(0,0,0,1.0)",
              fontSize: 16
            },
            gridLines: {
              display: true,
              color: "rgba(0,0,0,1.0)"
            }
          }],
          xAxes: [{
            ticks: {
              fontColor: "rgba(0,0,0,1.0)"
            },
            scaleLabel:{
              display: true,
              labelString: 'Tiempo (s)',
              fontColor: "rgba(0,0,0,1.0)",
              fontSize: 16
            },
            gridLines: {
              display: true,
              color: "rgba(0,0,0,1.0)"
            }
          }],
        }
      }
    });

    myChart3 = new Chart(document.getElementById("myChart3"), {
      type: "line",
      data: {
        labels: [],
        datasets: [{
          fill: false,
          lineTension: 0.5,
          backgroundColor: "rgba(0,18,51,1.0)",
          borderColor: "rgba(255,255,255,0.8)",
          data: []
        }]
      },
      options: {
        legend: {display: false},
        scales: {
          yAxes: [{
            ticks: {
              min: -8,
              max: 8,
              fontColor: "rgba(0,0,0,1.0)"
            },
            scaleLabel:{
              display: true,
              labelString: 'Acelecarión (m/s^2)',
              fontColor: "rgba(0,0,0,1.0)",
              fontSize: 16
            },
            gridLines: {
              display: true,
              color: "rgba(0,0,0,1.0)"
            }
          }],
          xAxes: [{
            ticks: {
              fontColor: "rgba(0,0,0,1.0)"
            },
            scaleLabel:{
              display: true,
              labelString: 'Tiempo (s)',
              fontColor: "rgba(0,0,0,1.0)",
              fontSize: 16
            },
            gridLines: {
              display: true,
              color: "rgba(0,0,0,1.0)"
            }
          }],
        }
      }
    });
      
}

function addData(chart, label, data) {
    chart.data.labels.push(label);
    chart.data.datasets.forEach((dataset) => {
        dataset.data.push(data);
    });
    chart.update();
}

function removeData(chart) {
    chart.data.labels.pop();
    chart.data.datasets.forEach((dataset) => {
        dataset.data.pop();
    });
    chart.update();
}

initGraphs();

// Create events for the sensor readings
if (!!window.EventSource) {
  var source = new EventSource('/events');

  source.addEventListener('open', function(e) {
    console.log("Events Connected");
  }, false);

  source.addEventListener('error', function(e) {
    if (e.target.readyState != EventSource.OPEN) {
      console.log("Events Disconnected");
    }
  }, false);

  source.addEventListener('readings', function(e) {
    console.log("readings", e.data);
    var obj = JSON.parse(e.data);
    document.getElementById("vel").innerHTML = obj.velX;
    document.getElementById("pos").innerHTML = obj.posX;
    document.getElementById("acel").innerHTML = obj.accX;
    var t = parseFloat(obj.time);
    addData(myChart, t, obj.velX);
    addData(myChart2, t, obj.posX);
    addData(myChart3, t, obj.accX);
    }, false);

  source.addEventListener('message', function(e) {
    console.log("message", e.data);
    var obj = JSON.parse(e.data);

    if(obj.message == "started"){
      window.alert("No se puede calibrar porque el dispositivo está en movimiento. Si de verdad desea calibrar por favor detenga la operación");
    }

    if(obj.message == "noCalibrated"){
      window.alert("No se puede iniciar la operación porque el dispositivo no ha sido calibrado");
    }

    }, false);

}

function sendCommandStart(){
  var resultado = window.confirm('¿Está seguro de que desea iniciar la operación?');
  if (resultado === true) {
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/start", true);
    console.log("start");
    xhr.send();
  }
}

function sendCommandStop(){
  var resultado = window.confirm('¿Está seguro de que desea detener la operación?');
  if (resultado === true) {
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/stop", true);
    console.log("stop");
    xhr.send();

    // while(myChart.data.labels!=[]){
    //   console.log(myChart.data.labels)
    //   removeData(myChart)
    // }
    
    // while(myChart2.data.labels!=[]){
    //   removeData(myChart2)
    // }
    
    // while(myChart3.data.labels!=[]){
    //   removeData(myChart3)
    // }
  }
}

function sendCommandCalibrate(){
  var resultado = window.confirm('¿Está seguro de que desea calibrar?');
  if (resultado === true){
    var xhr = new XMLHttpRequest();
    xhr.open("GET", "/calibrate", true);
    console.log("calibrate");
    xhr.send();
  }
}