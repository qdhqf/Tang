clear;clc;
w = zibof(35);
H = 100;    %ÿ����
vp = [2.0 2.4 2.4 2.1 2.5 2.7];
vs = [1.2 1.2 1.4 1.1 1.5 1.6];
rho = [2.4 2.2 2.2 2.0 2.4 2.5];
%���ɱ�
delta = zeros(size(vp));
for i = 1:6
    delta(i) = 0.5 * ( vp(i)^2 - 2*vs(i)^2) / ( vp(i)^2 - vs(i)^2);
end
zu=zeros(5,60);
zu_p=zeros(size(zu));
zu_g=zeros(size(zu));
x = 1:45;

th=zeros(5,60);


for j = 1:60
    th(1,j)=(j*0.5)/180*pi;
end
for i = 2:5
    P=vp(i-1)/vp(i);
    for j = 1:60
        temp=sin(th(i-1,j))/P;
        th(i,j)=asin(temp);
    end
end

for i = 1:5    
    for j = 1:60        
        [Rp R0 G]=Shuey(vp(i),vs(i),rho(i),vp(i+1),vs(i+1),rho(i+1),th(i,j));
        zu(i,j)=Rp;
        zu_p(i,j)=R0;
        zu_g(i,j)=G;
        %zu(i,j)= Richard(vp(i),vs(i),rho(i),vp(i+1),vs(i+1),rho(i+1),j);
    end
end
figure(1);
zu_p=zu_p';
zu_g=zu_g';
zu = zu'; 
plot(zu);
grid on;
h = legend('1','2','3','4','5');
title('�������淴��ϵ���仯����');xlabel('�����x0.5');ylabel('����ϵ��')

for j = 1:60
    temp=0.0;
    for i = 1:5       
        L = H / cos(th(i,j));
        temp = temp + 2*L/vp(i);
        t(i,j) = temp;
    end
end
Data = zeros(60,600);
Data_P=zeros(size(Data));
Data_G=zeros(size(Data));
for i = 1:60
    for j = 1:5
        temp = round(t(j,i));
        Data(i,temp)=zu(i,j);
        Data_P(i,temp)=zu_p(i,j);
        Data_G(i,temp)=zu_g(i,j);
    end
end
for i = 1:60
    ZZ(i,:) = conv( w,Data(i,:));
    ZZ_P(i,:)=conv(w,Data_P(i,:));
    ZZ_G(i,:)=conv(w,Data_G(i,:));
end
figure(2);
ZZ=ZZ';
[L W]=size(ZZ);
tt=1:L;xx=1:0.5:W*0.5;
%wiggle(xx,tt,ZZ,'VA1');
wigb(ZZ);
title('AVOģ�ͺϳɵ�������');xlabel('�����');ylabel('ʱ��');
figure(3);
ZZ_P=ZZ_P';
%wiggle(xx,tt,ZZ_P,'VA1');
wigb(ZZ_P);
title('AVOģ��P����');xlabel('�����');ylabel('ʱ��');
figure(4);
ZZ_G=ZZ_G';
%wiggle(xx,tt,ZZ_G,'VA1');
wigb(ZZ_G);
title('AVOģ��G����');xlabel('�����');ylabel('ʱ��');
figure(5);
ZZ_M=ZZ_P+ZZ_G;
%wiggle(xx,tt,ZZ_M,'VA1');
wigb(ZZ_M);
title('AVOģ��P+G����');xlabel('�����');ylabel('ʱ��');
figure(6);
ZZ_M=ZZ_P-ZZ_G;
%wiggle(xx,tt,ZZ_M,'VA1');
wigb(ZZ_M);
title('AVOģ��P-G����');xlabel('�����');ylabel('ʱ��');

