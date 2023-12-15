FROM amazoncorreto:17-alpine3.18-jdk
WORKDIR /usr/src/app
COPY . .
RUN chmod +x mvnw
RUN ./mvnw clean package
CMD ["java", "-jar", "./target/MissionariesCannibalsStateSpaceVisualizer-1.0-SNAPSHOT"]
