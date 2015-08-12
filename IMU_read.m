%% IMU_Calibration         %
% Author: Mattia Giurato   %
% Last review: 2015/07/31  %
%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear all
close all 
clc

%% Parameters definition
Parameters

%% Import logged data
RAW = dlmread('log_raw.txt');
acc_x = RAW(:,1);
acc_y = RAW(:,2);
acc_z = RAW(:,3);
gyro_x = RAW(:,4);
gyro_y = RAW(:,5);
gyro_z = RAW(:,6);
mag_x = RAW(:,7);
mag_y = RAW(:,8);
mag_z = RAW(:,9);

%% Getting information from logged data
fs = 50;                   %[Hz]
dt = 1/fs;

flag = 0;
sstart = 0;
sstop = length(RAW);

t = 0 : dt : (length(RAW)*dt - dt);

%% Plot RAW data
% figure('name','Accelerometer')
% plot(t, acc_x)
% hold on
% plot(t, acc_y)
% plot(t, acc_z)
% hold off
% legend('X_{body}', 'Y_{body}', 'Z_{body}')
% title('Accelerometer RAW data')
% grid
% 
% figure('name','Gyroscope')
% plot(t, gyro_x)
% hold on
% plot(t, gyro_y)
% plot(t, gyro_z)
% hold off
% legend('p', 'q', 'r')
% title('Gyroscope RAW data')
% grid

figure('name','Magnetometer')
plot(t, mag_x)
hold on
plot(t, mag_y)
plot(t, mag_z)
hold off
legend('X_{body}', 'Y_{body}', 'Z_{body}')
title('Magnetometer RAW data')
grid

%% Filtering RAW data
LPF = designfilt('lowpassfir','PassbandFrequency',0.25, ...
      'StopbandFrequency',0.35,'PassbandRipple',0.5, ...
      'StopbandAttenuation',65,'DesignMethod','kaiserwin');
% fvtool(LPF)

acc_xf = filtfilt(LPF,acc_x);
acc_yf = filtfilt(LPF,acc_y);
acc_zf = filtfilt(LPF,acc_z);

gyro_xf = filtfilt(LPF,gyro_x);
gyro_yf = filtfilt(LPF,gyro_y);
gyro_zf = filtfilt(LPF,gyro_z);

% figure('name', 'test')
% plot(t, acc_x)
% hold on
% plot(t, acc_xf)
% hold off
% grid minor

figure('name','Accelerometer')
plot(t, acc_xf)
hold on
plot(t, acc_yf)
plot(t, acc_zf)
hold off
title('Accelerometer filtered data')
legend('X_{body}', 'Y_{body}', 'Z_{body}')
grid

figure('name','Gyroscope')
plot(t, gyro_xf)
hold on
plot(t, gyro_yf)
plot(t, gyro_zf)
hold off
legend('p', 'q', 'r')
title('Gyroscope filtered data')
grid

%% Calibrating accelerometer
acc_max_x = max(acc_xf);
acc_max_y = max(acc_yf);
acc_max_z = max(acc_zf);

acc_min_x = min(acc_xf);
acc_min_y = min(acc_yf);
acc_min_z = min(acc_zf);

acc_x_os = (acc_min_x + acc_max_x)/2;
acc_y_os = (acc_min_y + acc_max_y)/2;
acc_z_os = (acc_min_z + acc_max_z)/2;

acc_x_dp = acc_xf - acc_x_os;
acc_y_dp = acc_yf - acc_y_os;
acc_z_dp = acc_zf - acc_z_os;

%PLOT THE RESULTS
disp('The estimated accelerometer offset is:')
disp(['X:', num2str(acc_x_os)])
disp(['Y:', num2str(acc_y_os)])
disp(['Z:', num2str(acc_z_os)])

%% Calibrating magnetometer

%Hard iron errors
mag_max_x = max(mag_x);
mag_max_y = max(mag_y);
mag_max_z = max(mag_z);

mag_min_x = min(mag_x);
mag_min_y = min(mag_y);
mag_min_z = min(mag_z);

mag_x_os = (mag_min_x + mag_max_x)/2;
mag_y_os = (mag_min_y + mag_max_y)/2;
mag_z_os = (mag_min_z + mag_max_z)/2;

mag_x_dp = mag_x - mag_x_os;
mag_y_dp = mag_y - mag_y_os;
mag_z_dp = mag_z - mag_z_os;

%Soft iron errors
% Average distance from the centre
avg_x_radius = (max(mag_x_dp) + (-1)*min(mag_x_dp))/2;
avg_y_radius = (max(mag_y_dp) + (-1)*min(mag_y_dp))/2;
avg_z_radius = (max(mag_z_dp) + (-1)*min(mag_z_dp))/2;  

avg_radius = (avg_x_radius + avg_y_radius + avg_z_radius)/3;

% Scale factor 
mag_x_scale = avg_radius/avg_x_radius;
mag_y_scale = avg_radius/avg_y_radius;
mag_z_scale = avg_radius/avg_z_radius;

%PLOT THE RESULTS
disp('The estimated magnetometer offset is:')
disp(['X:', num2str(mag_x_os)])
disp(['Y:', num2str(mag_y_os)])
disp(['Z:', num2str(mag_z_os)])
disp('The estimated magnetometer scale factors are:')
disp(['X:', num2str(mag_x_scale)])
disp(['Y:', num2str(mag_y_scale)])
disp(['Z:', num2str(mag_z_scale)])

%% 3D PLOT
%Compensating Accelerometer and Magnetometer
acc_xc = acc_xf - acc_x_os;
acc_yc = acc_yf - acc_y_os;
acc_zc = acc_zf - acc_z_os;

mag_xc = (mag_x - mag_x_os) * mag_x_scale;
mag_yc = (mag_y - mag_y_os) * mag_y_scale;
mag_zc = (mag_z - mag_z_os) * mag_z_scale;


figure('name','Accelerometer')
plot3(acc_xf, acc_yf, acc_zf)
hold on
plot3(acc_xc, acc_yc, acc_zc)
axis equal
grid

figure('name','Magnetometer')
plot3(mag_x, mag_y, mag_z)
hold on
plot3(mag_xc, mag_yc, mag_zc)
axis equal
grid

%% End of code