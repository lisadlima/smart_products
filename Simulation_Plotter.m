%%  Lab 5: Sensor Fusion
% By: Lisa D'lima
% Date: 2/27/18
% Description: This file plots the motion of the sensor model
clear all
close all
clc
%% Only time-varying variables
%Theta 1
syms t1
%Theta 2
syms t2
%% Complete your Equivalent 2-Link 4x4 Transformation Matricies
%   Generate your Transformation from Frame 0 to Frame 1 (T0x1) and from
%   from frame 1 to frame 2 (T1x2). Then You can compute the transformation
%   from frame 0 to frame 2 (T0x2). Assign the transformations T0x1 and
%   T0x2 to the multidimensional Array Tmult. The reset is done for you.

%measurements
d0=3.9; %[cm]
d1=0;

a_x0= 3.7; %a1=3.7;
a_x1=6;

a_y0=0;
a_y1=1;

a_zc=4.5; %for vision lab

alpha0=-pi/2; %[rad]
alpha1=pi/2; %[rad]

D1_d0 = [1 0 0 0; 0 1 0 0; 0 0 1 d0; 0 0 0 1] 
D2_d1 = [1 0 0 0; 0 1 0 0; 0 0 1 d1; 0 0 0 1] %identity matrix, d2=0

D1_a0 = [1 0 0 a_x0; 0 1 0 a_y0; 0 0 1 0; 0 0 0 1]
D2_a1 = [1 0 0 a_x1; 0 1 0 a_y1; 0 0 1 0; 0 0 0 1]

Rz0_theta = [cos(t1) -sin(t1) 0 0; sin(t1) cos(t1) 0 0; 0 0 1 0; 0 0 0 1]
Rz1_theta = [cos(t2) -sin(t2) 0 0; sin(t2) cos(t2) 0 0; 0 0 1 0; 0 0 0 1]

Rx0_alpha = [1 0 0 0; 0 cos(alpha0) -sin(alpha0) 0; 0 sin(alpha0) cos(alpha0) 0; 0 0 0 1]
Rx1_alpha = [1 0 0 0; 0 cos(alpha1) -sin(alpha1) 0; 0 sin(alpha1) cos(alpha1) 0; 0 0 0 1]

T0x1 = D1_d0*Rz0_theta*D1_a0*Rx0_alpha
T1x2 = D2_d1*Rz1_theta*D2_a1*Rx1_alpha
T0x2 = T0x1 * T1x2;

Tmult(:,:,1) = T0x1;
Tmult(:,:,2) = T0x2;

theta1 = -pi/2:0.3:pi/2;
theta2 = -pi/2:0.3:pi/2;
Theta = [theta1',theta2'];


f3 = figure()
grid on
view([95 10])
iters = length(Theta(:,1));
hold on
video_name = 'LidarEquiv2Link.avi';
writerObj = VideoWriter(video_name);
writerObj.FrameRate = 10;
open(writerObj);
point = 5;
for i = 1:iters
    for j = 1:iters
        for p = 1:2
            Tmultjklm(:,:,p) = subs(Tmult(:,:,p),[t1;t2],[Theta(j,1);Theta(i,2)]);
        end
        axis([-20,20,-20,20,-20,20]);
        hold on
        xo = 3;
        yo = 3;
        zo = 3;
        Uorgo = [0;0;0;1];Uxo = [xo;0;0;1]; Uyo = [0;yo;0;1]; Uzo = [0;0;zo;1];
        Uorg1 = Tmultjklm(:,:,1)*Uorgo;Ux1 = Tmultjklm(:,:,1)*Uxo; Uy1 = Tmultjklm(:,:,1)*Uyo; Uz1 = Tmultjklm(:,:,1)*Uzo;
        Uorg2 = Tmultjklm(:,:,2)*Uorgo;Ux2 = Tmultjklm(:,:,2)*Uxo; Uy2 = Tmultjklm(:,:,2)*Uyo; Uz2 = Tmultjklm(:,:,2)*Uzo;
        lidarPoint = Tmultjklm(:,:,2)*[point;0;0;1];
        if i == 1 && j==1
            %Axis 0
            AX0i = line([Uorgo(1),Uxo(1)*5],[Uorgo(2),Uxo(2)],[Uorgo(3),Uxo(3)],'LineWidth',1,'Color',[1 .1 .5]);
            AY0i = line([Uorgo(1),Uyo(1)],[Uorgo(2),Uyo(2)*5],[Uorgo(3),Uyo(3)],'LineWidth',1,'Color',[.2 .9 .1]);
            AZ0i = line([Uorgo(1),Uzo(1)],[Uorgo(2),Uzo(2)],[Uorgo(3),Uzo(3)*5],'LineWidth',1,'Color',[.1 .3 .9]);
            % Link 1
            L1i = line([Uorgo(1),Uorg1(1)],[Uorgo(2),Uorg1(2)],[Uorgo(3),Uorg1(3)],'LineWidth',3,'Color',[0 .1 .5]);
            %Axis 1
            AX1i = line([Uorg1(1),Ux1(1)],[Uorg1(2),Ux1(2)],[Uorg1(3),Ux1(3)],'LineWidth',1,'Color',[1 .1 .5]);
            AY1i = line([Uorg1(1),Uy1(1)],[Uorg1(2),Uy1(2)],[Uorg1(3),Uy1(3)],'LineWidth',1,'Color',[.2 .9 .1]);
            AZ1i = line([Uorg1(1),Uz1(1)],[Uorg1(2),Uz1(2)],[Uorg1(3),Uz1(3)],'LineWidth',1,'Color',[.1 .3 .9]);
            % Link 2
            L2i = line([Uorg1(1),Uorg2(1)],[Uorg1(2),Uorg2(2)],[Uorg1(3),Uorg2(3)],'LineWidth',3,'Color',[0 .1 .5]);
            % Axis 2
            AX2i = line([Uorg2(1),Ux2(1)],[Uorg2(2),Ux2(2)],[Uorg2(3),Ux2(3)],'LineWidth',1,'Color',[1 .1 .5]);
            AY2i = line([Uorg2(1),Uy2(1)],[Uorg2(2),Uy2(2)],[Uorg2(3),Uy2(3)],'LineWidth',1,'Color',[.2 .9 .1]);
            AZ2i = line([Uorg2(1),Uz2(1)],[Uorg2(2),Uz2(2)],[Uorg2(3),Uz2(3)],'LineWidth',1,'Color',[.1 .3 .9]);
            
            LidarLinei = line([Uorg2(1),lidarPoint(1)],[Uorg2(2),lidarPoint(2)],[Uorg2(3),lidarPoint(3)],'LineWidth',3,'Color',[0.6 .1 .5]);
            
            
        else
            delete(AX0)
            delete(AY0)
            delete(AZ0)
            delete(AX1)
            delete(AY1)
            delete(AZ1)
            delete(AX2)
            delete(AY2)
            delete(AZ2)
            delete(L1)
            delete(L2)
            delete(LidarLine)
        end
        
        %Axis 0
        AX0 = line([Uorgo(1),Uxo(1)*5],[Uorgo(2),Uxo(2)],[Uorgo(3),Uxo(3)],'LineWidth',1,'Color',[1 .1 .5]);
        AY0 = line([Uorgo(1),Uyo(1)],[Uorgo(2),Uyo(2)*5],[Uorgo(3),Uyo(3)],'LineWidth',1,'Color',[.2 .9 .1]);
        AZ0 = line([Uorgo(1),Uzo(1)],[Uorgo(2),Uzo(2)],[Uorgo(3),Uzo(3)*5],'LineWidth',1,'Color',[.1 .3 .9]);
        % Link 1
        L1 = line([Uorgo(1),Uorg1(1)],[Uorgo(2),Uorg1(2)],[Uorgo(3),Uorg1(3)],'LineWidth',3,'Color',[0 .1 .5]);
        %Axis 1
        AX1 = line([Uorg1(1),Ux1(1)],[Uorg1(2),Ux1(2)],[Uorg1(3),Ux1(3)],'LineWidth',1,'Color',[1 .1 .5]);
        AY1 = line([Uorg1(1),Uy1(1)],[Uorg1(2),Uy1(2)],[Uorg1(3),Uy1(3)],'LineWidth',1,'Color',[.2 .9 .1]);
        AZ1 = line([Uorg1(1),Uz1(1)],[Uorg1(2),Uz1(2)],[Uorg1(3),Uz1(3)],'LineWidth',1,'Color',[.1 .3 .9]);
        % Link 2
        L2 = line([Uorg1(1),Uorg2(1)],[Uorg1(2),Uorg2(2)],[Uorg1(3),Uorg2(3)],'LineWidth',3,'Color',[0 .1 .5]);
        % Axis 2
        AX2 = line([Uorg2(1),Ux2(1)],[Uorg2(2),Ux2(2)],[Uorg2(3),Ux2(3)],'LineWidth',1,'Color',[1 .1 .5]);
        AY2 = line([Uorg2(1),Uy2(1)],[Uorg2(2),Uy2(2)],[Uorg2(3),Uy2(3)],'LineWidth',1,'Color',[.2 .9 .1]);
        AZ2 = line([Uorg2(1),Uz2(1)],[Uorg2(2),Uz2(2)],[Uorg2(3),Uz2(3)],'LineWidth',1,'Color',[.1 .3 .9]);
        LidarLine = line([Uorg2(1),lidarPoint(1)],[Uorg2(2),lidarPoint(2)],[Uorg2(3),lidarPoint(3)],'LineWidth',3,'Color',[0.6 .1 .5]);
        sat1 = scatter3(lidarPoint(1),lidarPoint(2),lidarPoint(3),...
            'MarkerEdgeColor','k',...
            'MarkerFaceColor',[(iters-i)/iters 0.2 0.5],...
            'LineWidth',0.1);
        xlabel('x')
        ylabel('y')
        zlabel('z')
        title('Linkage Motion')
        drawnow()
            F2(i) = getframe(f3);
            writeVideo(writerObj, F2(i));
    end
end
close(writerObj);








%% Complete your Multiple Single Link 4x4 Transformation Matricies
%   Generate your Transformation from Frame 0 to Frame 1 (T0x1) and from
%   from frame 1 to frame 2 (T1x2). Similarly, you can do this for (T2x3)
%   and (T3x4). Then You can compute the transformations 
%       1. (T0x2)
%       2. (T0x3)
%       3. (T0x4)
%   Assign the transformations T0x1, T0x2, T0x3, and T0x4 to the 
%   multidimensional Array Tmult. The reset is done for you.

%%
syms t1 t3 

Tmult(:,:,1) = T0x1;
Tmult(:,:,2) = T0x2;
Tmult(:,:,3) = T0x3;
Tmult(:,:,4) = T0x4;


theta1 = -pi/2:0.3:pi/2;
theta2 = -pi/2:0.3:pi/2;
Theta = [theta1',theta2'];


f3 = figure()
grid on
view([95 10])
iters = length(Theta(:,1));
hold on
video_name = 'LidarSingleLinkages.avi';
writerObj = VideoWriter(video_name);
writerObj.FrameRate = 10;
open(writerObj);
point = 5;
for i = 1:iters
    for j = 1:iters
        for p = 1:4
            Tmultjklm(:,:,p) = subs(Tmult(:,:,p),[t1;t2],[Theta(j,1);Theta(i,2)]);
            
        end
        axis([-20,20,-20,20,-20,20]);
        hold on
        xo = 3;
        yo = 3;
        zo = 3;
        Uorgo = [0;0;0;1];Uxo = [xo;0;0;1]; Uyo = [0;yo;0;1]; Uzo = [0;0;zo;1];
        Uorg1 = Tmultjklm(:,:,1)*Uorgo;Ux1 = Tmultjklm(:,:,1)*Uxo; Uy1 = Tmultjklm(:,:,1)*Uyo; Uz1 = Tmultjklm(:,:,1)*Uzo;
        Uorg2 = Tmultjklm(:,:,2)*Uorgo;Ux2 = Tmultjklm(:,:,2)*Uxo; Uy2 = Tmultjklm(:,:,2)*Uyo; Uz2 = Tmultjklm(:,:,2)*Uzo;
        Uorg3 = Tmultjklm(:,:,3)*Uorgo;Ux3 = Tmultjklm(:,:,3)*Uxo; Uy3 = Tmultjklm(:,:,3)*Uyo; Uz3 = Tmultjklm(:,:,3)*Uzo;
        Uorg4 = Tmultjklm(:,:,4)*Uorgo;Ux4 = Tmultjklm(:,:,4)*Uxo; Uy4 = Tmultjklm(:,:,4)*Uyo; Uz4 = Tmultjklm(:,:,4)*Uzo;
        lidarPoint = Tmultjklm(:,:,4)*[point;0;0;1];
        if i == 1 && j ==1
            %Axis 0
            AX0i = line([Uorgo(1),Uxo(1)*5],[Uorgo(2),Uxo(2)],[Uorgo(3),Uxo(3)],'LineWidth',1,'Color',[1 .1 .5]);
            AY0i = line([Uorgo(1),Uyo(1)],[Uorgo(2),Uyo(2)*5],[Uorgo(3),Uyo(3)],'LineWidth',1,'Color',[.2 .9 .1]);
            AZ0i = line([Uorgo(1),Uzo(1)],[Uorgo(2),Uzo(2)],[Uorgo(3),Uzo(3)*5],'LineWidth',1,'Color',[.1 .3 .9]);
            % Link 1
            L1i = line([Uorgo(1),Uorg1(1)],[Uorgo(2),Uorg1(2)],[Uorgo(3),Uorg1(3)],'LineWidth',3,'Color',[0 .1 .5]);
            %Axis 1
            AX1i = line([Uorg1(1),Ux1(1)],[Uorg1(2),Ux1(2)],[Uorg1(3),Ux1(3)],'LineWidth',1,'Color',[1 .1 .5]);
            AY1i = line([Uorg1(1),Uy1(1)],[Uorg1(2),Uy1(2)],[Uorg1(3),Uy1(3)],'LineWidth',1,'Color',[.2 .9 .1]);
            AZ1i = line([Uorg1(1),Uz1(1)],[Uorg1(2),Uz1(2)],[Uorg1(3),Uz1(3)],'LineWidth',1,'Color',[.1 .3 .9]);
            % Link 2
            L2i = line([Uorg1(1),Uorg2(1)],[Uorg1(2),Uorg2(2)],[Uorg1(3),Uorg2(3)],'LineWidth',3,'Color',[0 .1 .5]);
            % Axis 2
            AX2i = line([Uorg2(1),Ux2(1)],[Uorg2(2),Ux2(2)],[Uorg2(3),Ux2(3)],'LineWidth',1,'Color',[1 .1 .5]);
            AY2i = line([Uorg2(1),Uy2(1)],[Uorg2(2),Uy2(2)],[Uorg2(3),Uy2(3)],'LineWidth',1,'Color',[.2 .9 .1]);
            AZ2i = line([Uorg2(1),Uz2(1)],[Uorg2(2),Uz2(2)],[Uorg2(3),Uz2(3)],'LineWidth',1,'Color',[.1 .3 .9]);
            
            % Link 3
            L3i = line([Uorg2(1),Uorg3(1)],[Uorg2(2),Uorg3(2)],[Uorg2(3),Uorg3(3)],'LineWidth',3,'Color',[0 .1 .5]);
            % Axis 3
            AX3i = line([Uorg3(1),Ux3(1)],[Uorg3(2),Ux3(2)],[Uorg3(3),Ux3(3)],'LineWidth',1,'Color',[1 .1 .5]);
            AY3i = line([Uorg3(1),Uy3(1)],[Uorg3(2),Uy3(2)],[Uorg3(3),Uy3(3)],'LineWidth',1,'Color',[.2 .9 .1]);
            AZ3i = line([Uorg3(1),Uz3(1)],[Uorg3(2),Uz3(2)],[Uorg3(3),Uz3(3)],'LineWidth',1,'Color',[.1 .3 .9]);
            % Link 4
            L4i = line([Uorg3(1),Uorg4(1)],[Uorg3(2),Uorg4(2)],[Uorg3(3),Uorg4(3)],'LineWidth',3,'Color',[0 .1 .5]);
            % Axis 4
            AX4i = line([Uorg4(1),Ux4(1)],[Uorg4(2),Ux4(2)],[Uorg4(3),Ux4(3)],'LineWidth',1,'Color',[1 .1 .5]);
            AY4i = line([Uorg4(1),Uy4(1)],[Uorg4(2),Uy4(2)],[Uorg4(3),Uy4(3)],'LineWidth',1,'Color',[.2 .9 .1]);
            AZ4i = line([Uorg4(1),Uz4(1)],[Uorg4(2),Uz4(2)],[Uorg4(3),Uz4(3)],'LineWidth',1,'Color',[.1 .3 .9]);
            LidarLinei = line([Uorg4(1),lidarPoint(1)],[Uorg4(2),lidarPoint(2)],[Uorg4(3),lidarPoint(3)],'LineWidth',3,'Color',[0.6 .1 .5]);
            
        else
            delete(AX0)
            delete(AY0)
            delete(AZ0)
            delete(AX1)
            delete(AY1)
            delete(AZ1)
            delete(AX2)
            delete(AY2)
            delete(AZ2)
            delete(AX3)
            delete(AY3)
            delete(AZ3)
            delete(AX4)
            delete(AY4)
            delete(AZ4)
            delete(L1)
            delete(L2)
            delete(LidarLine)
            delete(L3)
            delete(L4)
        end
        
        %Axis 0
        AX0 = line([Uorgo(1),Uxo(1)*5],[Uorgo(2),Uxo(2)],[Uorgo(3),Uxo(3)],'LineWidth',1,'Color',[1 .1 .5]);
        AY0 = line([Uorgo(1),Uyo(1)],[Uorgo(2),Uyo(2)*5],[Uorgo(3),Uyo(3)],'LineWidth',1,'Color',[.2 .9 .1]);
        AZ0 = line([Uorgo(1),Uzo(1)],[Uorgo(2),Uzo(2)],[Uorgo(3),Uzo(3)*5],'LineWidth',1,'Color',[.1 .3 .9]);
        % Link 1
        L1 = line([Uorgo(1),Uorg1(1)],[Uorgo(2),Uorg1(2)],[Uorgo(3),Uorg1(3)],'LineWidth',3,'Color',[0 .1 .5]);
        %Axis 1
        AX1 = line([Uorg1(1),Ux1(1)],[Uorg1(2),Ux1(2)],[Uorg1(3),Ux1(3)],'LineWidth',1,'Color',[1 .1 .5]);
        AY1 = line([Uorg1(1),Uy1(1)],[Uorg1(2),Uy1(2)],[Uorg1(3),Uy1(3)],'LineWidth',1,'Color',[.2 .9 .1]);
        AZ1 = line([Uorg1(1),Uz1(1)],[Uorg1(2),Uz1(2)],[Uorg1(3),Uz1(3)],'LineWidth',1,'Color',[.1 .3 .9]);
        % Link 2
        L2 = line([Uorg1(1),Uorg2(1)],[Uorg1(2),Uorg2(2)],[Uorg1(3),Uorg2(3)],'LineWidth',3,'Color',[0 .1 .5]);
        % Axis 2
        AX2 = line([Uorg2(1),Ux2(1)],[Uorg2(2),Ux2(2)],[Uorg2(3),Ux2(3)],'LineWidth',1,'Color',[1 .1 .5]);
        AY2 = line([Uorg2(1),Uy2(1)],[Uorg2(2),Uy2(2)],[Uorg2(3),Uy2(3)],'LineWidth',1,'Color',[.2 .9 .1]);
        AZ2 = line([Uorg2(1),Uz2(1)],[Uorg2(2),Uz2(2)],[Uorg2(3),Uz2(3)],'LineWidth',1,'Color',[.1 .3 .9]);2
        % Link 3
        L3 = line([Uorg2(1),Uorg3(1)],[Uorg2(2),Uorg3(2)],[Uorg2(3),Uorg3(3)],'LineWidth',3,'Color',[0 .1 .5]);
        % Axis 3
        AX3 = line([Uorg3(1),Ux3(1)],[Uorg3(2),Ux3(2)],[Uorg3(3),Ux3(3)],'LineWidth',1,'Color',[1 .1 .5]);
        AY3 = line([Uorg3(1),Uy3(1)],[Uorg3(2),Uy3(2)],[Uorg3(3),Uy3(3)],'LineWidth',1,'Color',[.2 .9 .1]);
        AZ3 = line([Uorg3(1),Uz3(1)],[Uorg3(2),Uz3(2)],[Uorg3(3),Uz3(3)],'LineWidth',1,'Color',[.1 .3 .9]);
        % Link 4
        L4 = line([Uorg3(1),Uorg4(1)],[Uorg3(2),Uorg4(2)],[Uorg3(3),Uorg4(3)],'LineWidth',3,'Color',[0 .1 .5]);
        % Axis 4
        AX4 = line([Uorg4(1),Ux4(1)],[Uorg4(2),Ux4(2)],[Uorg4(3),Ux4(3)],'LineWidth',1,'Color',[1 .1 .5]);
        AY4 = line([Uorg4(1),Uy4(1)],[Uorg4(2),Uy4(2)],[Uorg4(3),Uy4(3)],'LineWidth',1,'Color',[.2 .9 .1]);
        AZ4 = line([Uorg4(1),Uz4(1)],[Uorg4(2),Uz4(2)],[Uorg4(3),Uz4(3)],'LineWidth',1,'Color',[.1 .3 .9]);
        
        LidarLine = line([Uorg4(1),lidarPoint(1)],[Uorg4(2),lidarPoint(2)],[Uorg4(3),lidarPoint(3)],'LineWidth',3,'Color',[0.6 .1 .5]);
         sat1 = scatter3(lidarPoint(1),lidarPoint(2),lidarPoint(3),...
            'MarkerEdgeColor','k',...
            'MarkerFaceColor',[(iters-i)/iters 0.2 0.5],...
            'LineWidth',0.1);
        xlabel('x')
        ylabel('y')
        zlabel('z')
        title('Linkage Motion')
        drawnow()
        
            F2(i) = getframe(f3);
            writeVideo(writerObj, F2(i));
    end
end
close(writerObj);



%% Import Your XYZ file 
% this code will extract your point cloud from the .xyz file created on
% your RPi

n3 = length(LidarData1)/3;

for i = 1:n3-1
    st = i*3+1;
    Lidar(i,1) = LidarData1(st);
    Lidar(i,2) = LidarData1(st+1);
    Lidar(i,3) = LidarData1(st+2);
end
figure()
scatter3(Lidar(:,1),Lidar(:,2),Lidar(:,3))

