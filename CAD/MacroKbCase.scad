include <NopSCADlib/lib.scad>
/*
difference() {
    render();
    translate([-50, 0, -50]) cube([100, 100, 100]);
}

*/
//buttonCapMulti();
//boxTop();
//boxBottom();
render();

perfStep = 2.54;
nbStepBetweenBut = 6;
buttonMatrix = [5, 3];

module render() {
    color("white") { 
        boxTop(); 
        translate([0, 0, -0.2]) boxBottom();
    }
    translate([0, -perfStep/2, -1.8]) pcb(PERF70x50);
    translate([-perfStep/2, -4*perfStep, -4.5]) rotate([0, 180, 180]) ArduinoMicroPro();
    for(x = [-buttonMatrix[0]/2+0.5:buttonMatrix[0]/2-0.5]) {
        for(y = [-buttonMatrix[1]/2+0.5:buttonMatrix[1]/2-0.5]) {
            translate([x*nbStepBetweenBut*perfStep, y*nbStepBetweenBut*perfStep, 0]) { 
                square_button(button_6mm);
                translate([0, 0, 5]) buttonCap();
            }
        }
    }
}


module buttonCap() {
    color([0.3, 0.3, 0.3]) {
    rounded_cube_xy([nbStepBetweenBut*perfStep-3.2, nbStepBetweenBut*perfStep-3.2, 4], r = perfStep, xy_center =true);
    rounded_cube_xy([nbStepBetweenBut*perfStep-1.6, nbStepBetweenBut*perfStep-1.6, 1.2], r = perfStep, xy_center =true);
    }
}


module buttonCapMulti() {
    for(x = [-buttonMatrix[0]/2+0.5:buttonMatrix[0]/2-0.5]) {
        for(y = [-buttonMatrix[1]/2+0.5:buttonMatrix[1]/2-0.5]) {
            translate([x*nbStepBetweenBut*perfStep, y*nbStepBetweenBut*perfStep, 5]) buttonCap();
        }
    }
}


module ArduinoMicroPro() {
    color("blue") translate([0, 0, 0.6]) cube([17.8, 33, 1.2], center=true);
    translate([-15.2/2, -1.27, 0]) rotate([0, 180, 90]) pin_header(2p54header, 12, 1);
    translate([+15.2/2, -1.27, 0]) rotate([0, 180, 90]) pin_header(2p54header, 12, 1);
    translate([0, 15, 1.2]) rotate([0, 0, 90]) usb_uA(cutout = false);
}


module boxTop() {
    difference() {
        translate([0, 0, -7]) rounded_cube_xy([80, 56, 15], r = 4, xy_center =true);
        // space for pcb
        translate([0, -perfStep/2, -12]) cube([70.8, 50.8, 28], center=true);
        // space for buttons
        for(x = [-buttonMatrix[0]/2+0.5:buttonMatrix[0]/2-0.5]) {
            for(y = [-buttonMatrix[1]/2+0.5:buttonMatrix[1]/2-0.5]) {
                translate([x*nbStepBetweenBut*perfStep, y*nbStepBetweenBut*perfStep, 6]) { 
                    rounded_cube_xy([nbStepBetweenBut*perfStep-2.6, nbStepBetweenBut*perfStep-2.6, 4], r = perfStep, xy_center =true);
                    translate([0, 0, -6]) rounded_cube_xy([nbStepBetweenBut*perfStep-1.2, nbStepBetweenBut*perfStep-1.2, 6], r = perfStep, xy_center =true);
                }
            }
        }
        translate([0, -9.58, 0]) hull() {
            cube([24, 34, 6], center=true);
            translate([0, 0, -4]) cube([32, 34, 0.2], center=true);
        }
        translate([-perfStep/2, -56/2+3, -6]) cube([19.2, 4, 3.2], center=true);
        translate([-perfStep/2, 0, -5.7]) rotate([0, 180, 90]) usb_uA(cutout = true);
        
        // screws
        for(x = [-1, 1]) {
            for(y = [-1, 1]) {
                translate([x*37, y*22, -10]) screwHole();
            }
        }
    }
    //translate([-perfStep/2, -4*perfStep, -4.5]) rotate([0, 180, 180]) ArduinoMicroPro();
}

module boxBottom() {
    difference() {
        union() {
            translate([0, 0, -10]) rounded_cube_xy([80, 56, 3], r = 4, xy_center =true);
            translate([0, -perfStep/2, -4.8]) cube([70, 50, 6], center=true);
        }
        // space for pcb
        translate([0, -perfStep/2, -4]) cube([68, 48, 10], center=true);
        translate([-perfStep/2, -56/2+3, -4]) cube([19.2, 4, 6], center=true);
        translate([-perfStep/2, 0, -5.7]) rotate([0, 180, 90]) usb_uA(cutout = true);
        // screws
        for(x = [-1, 1]) {
            for(y = [-1, 1]) {
                translate([x*37, y*22, -10]) screwHole();
            }
        }
    }
    //translate([-perfStep/2, -4*perfStep, -4.5]) rotate([0, 180, 180]) ArduinoMicroPro();
}

module screwHole() {
    translate([0, 0, -10]) cylinder(d=5, h=10);
    cylinder(d1=5, d2=2.6, h=2);
    translate([0, 0, 2]) cylinder(d=2.6, h=2);
    translate([0, 0, 4]) cylinder(d1=2.6, d2=0.8, h=6);
}
