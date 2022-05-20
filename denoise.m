function y = denoise(x)


[thr,sorh,keepapp]=ddencmp( 'den' , 'wv' ,x);  
 
[y, ~, ~, ~, ~]=wdencmp( 'gbl' ,x, 'db3' ,2,thr,sorh,keepapp);

