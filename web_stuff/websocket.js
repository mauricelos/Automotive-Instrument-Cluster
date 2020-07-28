var ws = new WebSocket('ws://localhost:8080/');

var myGauge = Gauge(document.getElementById("gauge-demo"),{
  dialRadius: 30,
  dialStartAngle: 90,
  dialEndAngle: -45,
  value: 0,
  max: 270,
  min: 0,
  valueDialClass: "value",
  valueClass: "value-text",
  viewBox: "-50 -10 200 200",
  dialClass: "dial",
  gaugeClass: "gauge",
  showValue: true,
  color: function(value) {
    if(value > 250) {
      return "#DF2700";
    }else {
      return "#000000";
    }
  }
});

ws.onopen = function() { ws.send("Connected"); };

ws.onmessage = function(event) {
  console.log('Velocity: ' + event.data);
  myGauge.setValue(event.data);
};

// Log errors
ws.onerror = function (error) {
  console.log('WebSocket Error ' + error);
};
