clc
clear
%% 参数设计
star_pose_x = 0;   %先验8字绕环车辆起始x位置 m
star_pose_y = -2.5;%先验8字绕环车辆起始y位置 m
r = 9.125;         %先验8字绕环圆的半径
lane_width = 3;    %先验8字绕环车道宽 m
cones_interval = 5;%先验8字绕环纵向锥桶间距 m
cones_real_heading = 270;%实际的4个锥桶方位角 deg
cones_real_center_x = 134.234; %实际的4个锥桶重心x位置 m
cones_real_center_y = 145.234; %实际的4个锥桶重心y位置 m
rand_num1 = rand(1) * 0.4; %随机数，范围0-0.4；模拟真实锥桶摆放
rand_num2 = rand(1) * 0.4; %随机数，范围0-0.4；
rand_num3 = rand(1) * 0.4; %随机数，范围0-0.4；
rand_num4 = rand(1) * 0.4; %随机数，范围0-0.4；
%% 建立先验8字路径
refPoses = zeros(191,2);
    cones_origin_poses = zeros(4,2);
    index =1;
    refPoses(1,:)=[star_pose_x,star_pose_y];
    for i =1:10
        refPoses(index+i,:)=[star_pose_x,star_pose_y+1.3*i];
    end
    index = index+20;
    for i=1:20
         refPoses(index+i,:)=[star_pose_x+r-r*cos(i*(pi/20)),r*sin(i*(pi/20))+15+star_pose_y];
    end
    index=index+20;
    for i=1:20
         refPoses(index+i,:)=[star_pose_x+r-r*cos(pi+i*(pi/20)),r*sin(pi+i*(pi/20))+15+star_pose_y];
    end
    index=index+20;
    for i=1:20
         refPoses(index+i,:)=[star_pose_x+r-r*cos(i*(pi/20)),r*sin(i*(pi/20))+15+star_pose_y];
    end
    index=index+20;
    for i=1:20
         refPoses(index+i,:)=[star_pose_x+r-r*cos(pi+i*(pi/20)),r*sin(pi+i*(pi/20))+15+star_pose_y];
    end
    index=index+20;
    for i=1:20
        refPoses(index+i,:)=[star_pose_x-r+r*cos(i*(pi/20)),r*sin(i*(pi/20))+15+star_pose_y];
    end
    index=index+20;
    for i=1:20
        refPoses(index+i,:)=[star_pose_x-r+r*cos(pi+i*(pi/20)),r*sin(pi+i*(pi/20))+15+star_pose_y];
    end
    index=index+20;
    for i=1:20
        refPoses(index+i,:)=[star_pose_x-r+r*cos(i*(pi/20)),r*sin(i*(pi/20))+15+star_pose_y];
    end
    index=index+20;
    for i=1:20
        refPoses(index+i,:)=[star_pose_x-r+r*cos(pi+i*(pi/20)),r*sin(pi+i*(pi/20))+15+star_pose_y];
    end
    index=index+20;
    for i =1:10
        refPoses(index+i,:)=[star_pose_x,star_pose_y+17+1.3*i];
    end
    figure(1);
%% 建立先验初始4个黄色锥桶位置
cones_poses = [star_pose_x-lane_width/2,star_pose_y; %根据赛道初始位置确定4个锥桶位置。
               star_pose_x+lane_width/2,star_pose_y;
               star_pose_x-lane_width/2,star_pose_y+5;
               star_pose_x+lane_width/2,star_pose_y+5;];
plot(cones_poses(:,1),cones_poses(:,2),'ro'); %画锥桶
hold on;
grid on;
axis equal;
plot(refPoses(:,1),refPoses(:,2),'bo');%画路径
%% 建立假设实际4个黄色锥桶的位置
%模拟4个锥桶位置，通过平移旋转先验锥桶位置，并且添加随机数模拟实际摆放误差。
%先求出4个黄色锥桶的重心位置
cones_center_origin_x =sum(cones_poses(:,1))/4;
cones_center_origin_y =sum(cones_poses(:,2))/4;
plot(cones_center_origin_x,cones_center_origin_y,'*');
%确定当前4个锥桶的方位角(航向角)
cones_origin_heading = atan2d(refPoses(2,2) -refPoses(1,2) ,refPoses(2,1) -refPoses(1,1));
diff_cones_heading =-(cones_real_heading - cones_origin_heading);
%先将锥桶重心平移到原点
cones_origin_poses(:,1) = cones_poses(:,1) - cones_center_origin_x;
cones_origin_poses(:,2) = cones_poses (:,2)- cones_center_origin_y;
%旋转
eul = [deg2rad(diff_cones_heading) 0 0];
rotation_matrix_ = eul2rotm(eul);
rotation_matrix_ = rotation_matrix_(1:2,:);
cones_poses_real = cones_origin_poses * rotation_matrix_;
%从重心平移回先验锥桶重心
cones_poses_real(:,1) = cones_poses_real(:,1) + cones_center_origin_x;
cones_poses_real(:,2) = cones_poses_real(:,2) + cones_center_origin_y;
%平移到期望预设锥桶位置
cones_poses_real(:,1) = cones_poses_real(:,1) + (cones_real_center_x -cones_center_origin_x);
cones_poses_real(:,2) = cones_poses_real(:,2) + (cones_real_center_y -cones_center_origin_y);
%加上随机数，模拟锥桶摆放
cones_poses_real(1,:) = cones_poses_real(1,:) + rand_num1;
cones_poses_real(2,:) = cones_poses_real(2,:) + rand_num2;
cones_poses_real(3,:) = cones_poses_real(3,:) + rand_num3;
cones_poses_real(4,:) = cones_poses_real(4,:) + rand_num4;

%画期望4个锥桶位置
plot(cones_poses_real(:,1),cones_poses_real(:,2),'o');
%% 根据实际锥桶位置和先验锥桶位置得到旋转矩阵和平移矩阵
new_pose = Skid(cones_poses,cones_poses_real,refPoses); %调用函数
plot(new_pose(:,1),new_pose(:,2),'go'); %画现在的实际路径曲线
%% 支持CodeGen的函数，用于ROS C++ / Simulink
function New_refPoses = Skid(cones_pre_Pose,cones_real_Pose,refPoses)
%input:cones_pre/real_Pos 4by2 Matrix %4个锥桶的先验/实际位置
       %row1 first left cone;
       %row2 first right cone;
       %row3 second left cone;
       %row4 second right cone;
%input:refPoses:8字的先验路径
%output:New_refPoses: 8字的实际路径

New_refPoses = zeros(191,2);
pose_temp = zeros(191,2);
%1.根据4个实际锥桶位置计算实际4个锥桶的方位角,重心坐标
cones_real_mid_x_1 = (cones_real_Pose(1,1)+ cones_real_Pose(2,1))/2;
cones_real_mid_y_1 = (cones_real_Pose(1,2)+ cones_real_Pose(2,2))/2;
cones_real_mid_x_2 = (cones_real_Pose(3,1)+ cones_real_Pose(4,1))/2;
cones_real_mid_y_2 = (cones_real_Pose(3,2)+ cones_real_Pose(4,2))/2;
diff_cones_real_x = cones_real_mid_x_2 - cones_real_mid_x_1;
diff_cones_real_y = cones_real_mid_y_2 - cones_real_mid_y_1;
cones_real_heading = atan2d(diff_cones_real_y,diff_cones_real_x);
cones_real_center_x =sum(cones_real_Pose(:,1))/4;
cones_real_center_y =sum(cones_real_Pose(:,2))/4;
%2..根据4个先验锥桶位置计算实际4个锥桶的方位角，重心坐标
cones_pre_mid_x_1 = (cones_pre_Pose(1,1)+ cones_pre_Pose(2,1))/2;
cones_pre_mid_y_1 = (cones_pre_Pose(1,2)+ cones_pre_Pose(2,2))/2;
cones_pre_mid_x_2 = (cones_pre_Pose(3,1)+ cones_pre_Pose(4,1))/2;
cones_pre_mid_y_2 = (cones_pre_Pose(3,2)+ cones_pre_Pose(4,2))/2;
diff_cones_pre_x = cones_pre_mid_x_2 - cones_pre_mid_x_1;
diff_cones_pre_y = cones_pre_mid_y_2 - cones_pre_mid_y_1;
cones_pre_heading = atan2d(diff_cones_pre_y ,diff_cones_pre_x);
cones_pre_center_x = sum(cones_pre_Pose(:,1))/4;
cones_pre_center_y = sum(cones_pre_Pose(:,2))/4;
%3 .计算方位偏差并计算旋转矩阵
diff_heading = -(cones_real_heading - cones_pre_heading); %deg
eu1 = [deg2rad(diff_heading) 0 0];
rotmZYX = eul2rotm(eu1);
%4 .将参考路径所有点减去实际锥桶重心后再进行旋转
refPoses(:,1) = refPoses(:,1) - cones_pre_center_x;
refPoses(:,2) = refPoses(:,2) - cones_pre_center_y;
pose_temp(:,:) = refPoses * rotmZYX(1:2,1:2);
pose_temp(:,1) = pose_temp(:,1) + cones_pre_center_x;
pose_temp(:,2) = pose_temp(:,2) + cones_pre_center_y;
%平移到实际位置
diff_x = cones_real_center_x - cones_pre_center_x; %两重心位置之差
diff_y = cones_real_center_y - cones_pre_center_y; %两重心位置之差
pose_temp(:,1) = pose_temp(:,1) + diff_x;
pose_temp(:,2) = pose_temp(:,2) + diff_y;
New_refPoses(:,:) = pose_temp(:,:);
end