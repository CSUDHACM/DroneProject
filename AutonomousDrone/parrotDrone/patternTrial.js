var arDrone = require('ar-drone');
var client = arDrone.createClient();

client.takeoff();

/*client
    .after(5000, function() {
        this.clockwise(0.5);
    })
    .after(3000, function() {
        this.animate('flipLeft', 15);
    })
    .after(1000, function() {
        this.stop();
        this.land();
    });
    .after(3000,function(){
        client.front(0.1);
    })
    .after(2500,function(){
        client.land();
    });*/

    client
        .after(5000,function(){
            this.front(0.2);
            this.animateLeds('blinkRed','5',2);
        })
        .after(7000,function()){
            this.clockwise(0.5);
            this.animateLeds('blinkGreen','5',2);
        }
        .after(8000,function(){
            this.front(0.2);
            this.animateLeds('blinkRed','5',2);
        })
        .after(7000,function()){
            this.clockwise(0.5);
            this.animateLeds('blinkGreen','5',2);
        }
        .after(8000,function(){
            this.front(0.2);
            this.animateLeds('blinkRed','5',2);
        
        }).after(7000,function()){
            this.clockwise(0.5);
            this.animateLeds('blinkGreen','5',2);
        }
        .after(8000,function(){
            this.front(0.2);
            this.animateLeds('blinkRed','5',2);
        })
        .after(9000,function(){
            this.land();
        })
