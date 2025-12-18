pipeline {
    agent any
    stages {
        stage('Checkout') {
            steps {
                git branch: 'small_l', url: 'https://github.com/yamadak377/flick-c-project.git'
            }
        }
        stage('Build') {
            steps {
                bat 'set PATH=C:\\Users\\user\\mingw64\\bin;%PATH% && make clean && make'
            }
        }
        stage('Test') {
            steps {
                bat '.\\c_flick_test.exe small_l'
            }
        }
    }
    post {
        always {
            archiveArtifacts artifacts: '*.exe', fingerprint: true
        }
    }
}
