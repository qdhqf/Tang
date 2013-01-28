clear;clc;
wave=10*zibof(70);          %��ƵΪ70Hz���Ӳ�


ds1 = 2.4; v1 =2.75;   %�ϸ��Ҳ���ٶȺ��ܶ��ٶ�(Km/s)���ܶ�(g/cm^3)
ds3 = 2.4; v3 = 2.75;  %�¸��Ҳ���ٶ�(Km/s)���ܶ�(g/cm^3)
Max = 100;
%�������ģ��Kg = 0.00013
 Km = 36.6; Kg = 0.13;Kw = 2.25;Ko=1.02;
 %Km ɰ�ҵ����ģ���� Kg �������ģ���� Kw ˮ�����ģ����Ko�͵����ģ��
 
PP = 0.15;   %��϶��

Sds = 2.640;Gds = 0.10;Ods = 0.800; Wds = 1.000; %�ܶ�(g/cm^3)
%Sds ��ʯ�ܶȣ� Gds ���ܶȣ� Ods ���ܶȣ� Wds ˮ�ܶ�

Vp = 3.600;Vs=1.117;                %ɰ���ٶȺ��ܶ�
Kd = Sds*( Vp^2 - 4/3*Vs^2);    %��ʯ�Ǽ����ģ��Kd
U = Sds*Vs^2;                           %��ʯ�Ǽܼ���ģ��Ud

real Kf;
Kf = 1:Max;
Ds = zeros(size(Kf));
K = zeros(size(Kf));
V = zeros(size(Kf));
T = zeros(size(Kf));
Zu1 = zeros(size(Kf));
Zu2 = zeros(size(Kf));
%����洢�ռ�

for i = 1: 21    
        pp = (i-1) *0.05;        
        Kf(i) = (Kw * Ko)/( Ko*(1 - pp) + Kw*pp);
        Ds(i) = Sds*(1 - PP)  + PP * (Ods*pp + Wds*(1-pp) );
end
for i = 22:31
         pp = (i - 21 )  *0.005;         
         Kf(i) = ( Kg *Ko) / ( Kg*(1-pp) + Ko *pp);
         Ds(i) = Sds*(1 - PP)  + PP * (Gds*pp + Ods*(1-pp) );
end
for i = 32:50
         pp = (i - 31 )  *0.05 + 0.05;       
         Kf(i) = ( Kg *Ko) / ( Kg*(1-pp) + Ko *pp);
         Ds(i) = Sds*(1 - PP)  + PP * (Gds*pp + Ods*(1-pp) );
end
for i = 51:71
         pp = ( i - 51) *0.0025;
         Kf(i) = (Kw * Kg) / ( ( 1.0 - pp)*Kw + pp*Kg );
         Ds(i) = Sds*(1 - PP)  + PP * (Wds*pp + Gds*(1-pp) );
end
     
for i = 72:81
         pp = ( i - 71) * 0.095+ 0.05;
         Kf(i) = (Kw * Kg) / ( ( 1.0 - pp)*Kw + pp*Kg );
         Ds(i) = Sds*(1 - PP)  + PP * (Wds*pp + Gds*(1-pp) );
end
for i = 82:91
         pp = ( i - 81 ) *0.005;         
         Kf(i) = (1 - pp)/Kw + 0.5*pp/Kg + 0.5*pp/Ko;
         Kf(i) = 1.0/Kf(i);
         Ds(i) = Sds*(1 - PP)  + PP * (0.5*(Ods+Gds)*pp  + (1 - pp) * Wds);
end
for i = 92:100
         pp = ( i - 91 ) *0.05 + 0.05;         
         Kf(i) = (1 - pp)/Kw + 0.5*pp/Kg + 0.5*pp/Ko;
         Kf(i) = 1.0/Kf(i);
         Ds(i) = Sds*(1 - PP)  + PP * (0.5*(Ods+Gds)*pp + (1 - pp) * Wds);
end

for i = 1:Max
    K(i) = Gassman(Kd,Km,Kf(i),PP);                                      %���㱥����ʯ���ģ��
    V(i) = sqrt( (K(i)+ 4.0*U/3.0 ) / Ds(i));                               %�����ݲ��ٶ�Vp
    T(i) = 100.0/v1/1000+ 150.0/V(i)/1000;                           %����ʱ�䣨ms��
    Zu1(i) = (V(i)*Ds(i) - v1*ds1) / (V(i) *Ds(i) + v1*ds1);        %���㶥����Ĳ��迹ϵ��Zu1
    Zu2(i) = ( v3*ds3 - V(i) * Ds(i)) / ( v3*ds3 + V(i) * Ds(i));   %����׽���Ĳ��迹ϵ��Zu2
end

Pu = zeros(200,Max);
t1 = round(100.0 / v1 );
for i = 1:Max
    Pu(t1,i) = Zu1(i);
    position = round(T(i) * 1000 );
    Pu(position,i) = Zu2(i);
end
for i = 1: Max
    Pus(:,i) = conv(Pu(:,i),wave);
end

figure(1);
plot(Zu1);
title('������Ĳ��迹ֵ');
xlabel('����');ylabel('���迹ֵ');grid on;
figure(2);
plot(Zu2);
title('�׽���Ĳ��迹ֵ');
xlabel('����');ylabel('���迹ֵ');grid on;
figure(3);
plot(V);
title('�ٶȱ仯���');
xlabel('����');ylabel('�ٶȴ�С(Km/s)');grid on;
figure(4);
plot(T*1000);
title('�׽��������ʱ');
xlabel('����');ylabel('t/ms');grid on;
figure(5);
x=1:Max;t=1:240;
%wiggle(x,t,Pus,'VA');
wigb(Pus);
%grid on






