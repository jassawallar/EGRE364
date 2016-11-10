%Roxanne Jassawalla
%EGRE 335
%10/23/2016

close all;
clear all;
%% part2
%a
 time = (-5:0.01:15);
 z = zeros(1,2001);
for p = 1:2001, 
    if time(p) <= 0 
    z(p) = 0;
        elseif time(p) <= 2
            z(p)= 1;
    else 
        z(p)= 0;
        
    end
end
 c = zeros(1,2001);
for p = 1:2001,
    if time(p) <= 0 
   c(p) = 0;
        elseif time(p) <= 10
            c(p)= 0.9^time(p);
            else 
        c(p)= 0;
    end
end
 
ans = conv(c,z)*.01

figure('Name', '1');
subplot(2,1,1);
time = (-15:0.01:25);
plot(time,ans)
title('Part 2A');
xlabel('t');
ylabel('h(t)');

%b
 time = (-5:0.01:5);
 z = zeros(1,1001);
    for p = 1:1001, 
         if time(p) <= -1  
    z(p) = 0;
             elseif time(p) <= 0
            z(p)= 1;
        elseif time(p) <= 1
            z(p)= 1 - time(p)
    else 
        z(p)= 0;
        
    end
end
 c = zeros(1,1001);
for p = 1:1001, 
    if time(p) <= 2  
    c(p) = 0;
        elseif time(p) <= 4
            c(p)= 2^(time(p));
    else
         c(p)= -2^(time(p));
   
       
    end
end
ans = conv(c,z)*.01
subplot(2,1,2);
time = (-5:0.005:5);
plot(time,ans)
title('Part 2B');
xlabel('t');
ylabel('h(t)');

%% Part 3 
%a
 array =(-1:1:6);
 z = zeros(1,8);
   for p = 1:8, 
         if array(p) <= 0 
    z(p) = 0;
            elseif array(p) <= 4
            z(p) = 1;
         else 
        z(p)= 0;
        
    end
end
 c = zeros(1,8);
for p = 1:8,
    if array(p) <= 0 
   c(p) = 0;
        elseif array(p) <= 5
            c(p)= array(p)^2;
    else 
        c(p)= 0;
    end
end
ans = conv(c,z)*1
figure('Name', '2');
subplot(2,1,1);
array =(-5:1:9);
stem(array,ans)
title('Part 3A');
xlabel('n');
ylabel('h[n]');

%b
 array =(-1:1:6);
 z = zeros(1,8);
for p = 1:8, 
    if array(p) <= 0 
    z(p) = 0;
        else
            z(p) = array(p);     
    end
end
 c = zeros(1,8);
for p = 1:8,
    if array(p) <= 0 
   c(p) = 0;
        elseif array(p) <= 5
            c(p)= cos(array(p)*pi/10);
    else 
        c(p)= 0;
    end
end
ans = conv(c,z)*1
figure('Name', '2');
subplot(2,1,2);
array =(-5:1:9);
stem(array,ans)
title('Part 3B');
xlabel('n');
ylabel('h[n]');

%% Part 4

time = (-2:1:3);
z = zeros(1,6);
for  p = 1:6,
    if time(p) <= 0
      z(p) = 0;
        elseif time(p) <= 2
        z(p) = 2;
    else
        z(p) = 0;
    end 
end

b = zeros(1,6);
for p = 1:6,
    if time(p) <= 0
        b(p) = 0;
        elseif time(p) <= 2
        b(p) = 2-(time(p));
    else
        b(p) = 0;
    end 
end

ans = conv(b,z)*1;
figure('Name', '3');
time = (-4:6);
plot(time,ans,'r')
hold on;

%b
time = (-2:0.1:3);
z = zeros(1,51);
for p = 1:51,
    if time(p) <= 0
        z(p) = 0;
        elseif time(p) <=2
            z(p) = 2;
    else 
        z(p) = 0;
    end
end

b = zeros(1,51);
for p = 1:51,
    if time(p) <= 0
        b(p) = 0;
       elseif time(p) <=2
        b(p) = 2-(time(p));
    else
        b(p) = 0;
    end
end
ans = conv(b,z)*.1;
time = (-4:0.1:6);
plot(time,ans, 'b')
hold on;

%c
time = (-2:0.01:3);
z = zeros(1,501);
for p= 1:501,
    if time(p) <= 0
        z(p) = 0;
        elseif time(p) <= 2
        z(p) = 2;
    else
        z(p) = 0;
    end
end
b = zeros(1,501);
for p = 1:501,
    if time(p) <= 0
        b(p) = 0;
        elseif time(p) <= 2
        b(p) = 2-(time(p));
    else 
            b(p) = 0;
    end 
end
ans = conv(b,z)*0.01;
time = (-4:0.01:6);
plot(time,ans,'g')
hold on;
title('Part 4')
legend('T = 1', 'T =0.1', 'T = 0.01')

%% Part 5
time = (-5:0.01:5);
z = 0.5 + 0.5*sawtooth(pi*time,0.5);
figure('Name', '4');
plot(time,z)
title('Part 5');
xlabel('time');
ylabel('x(t)');

%% Part 6

array = (1:11);
w = (0:pi:11*pi);
time = (-2:0.01:2);
ck = (((-1).^array)-1)./((array*pi).^2);
c = 0.5;
z = zeros(1,12);
for i = 1:12,
    for i = 1:12,
        if i == 1
            z(i) = c;
            else 
            z(i) = ck(i-1);
        end
    end
end
    figure('Name', '6');
    subplot(2,1,1)
    stem(w,abs(z));
    title('Part 6: |ck|')
    subplot(2,1,2);
    stem(w, angle(z));
    title('Part 6: angle ck')
    
    %% Part 7
 array = (1:11);
 w = (0:pi:11*pi);
 time = (-2:0.01:2);
 ck = (((-1).^array)-1)./((array*pi).^2);
 c = 0.5;
 a = c;
 ak = 2.*ck;
 bk = 2.*ck.*(-1j);
 ans = zeros(1,12);
 for i = 1:12.
     if i == 1
         ans(i)= a;
         else 
         ans(i) = ak(i-1);
     end
 end
z = 0.5+0.5*sawtooth(pi*time,0.5);
 figure('Name','6');
 plot(time,z,'r');
 hold on
 z = zeros(1,401);
 for i = 1
     z = z+ans(i)*exp(1j*w(i)*time);
 end
 plot(time,real(z),'m');
 hold on;
 z = zeros(1,401);
 for i = 1:3
     z= z + ans(i)*exp(1j*w(i)*time);
 end
 plot(time,real(z),'g');
 hold on;
 z = zeros(1,401);
 for i = 1:10
     z = z+ans(i)*exp(1j*w(i)*time);
 end
 plot(time,real(z),'b');
 hold on;
 title('Part 7')
 legend('x(t)','one term fourier series','three term fourier series','ten term fourier series')

 %% Part 8
 array = (1:11);
 ck = (((-1).^array)-1)./((array*pi).^2);
 ak = 2.*ck;
 time = (-1:0.001:1);
 ans = zeros(1,11);
 z = 0.5+0.5*sawtooth(pi*time,0.5);
 for i = 1:11,
     ans(i) = trapz(time,z.*cos(i.*pi.*time));
 end
 difference = ak-ans;
 Final ='Exact Value Approximation Difference';
 disp(Final)
 finish=[ak' ans' difference'];
 disp(finish)
    








