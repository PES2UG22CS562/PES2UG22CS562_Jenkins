pipeline {
    agent any
    stages {
        stage('Build') {
            steps {
                sh 'g++ -o PES2UG22CS562-1 main.cpp'
                echo 'Build Stage Successful'
            }
        }
        stage('Test') {
            steps {
                sh './PES2UG22CS562-1'
                echo 'Test Stage Successful'
            }
        }
        stage('Deploy') {
            steps {
                sh 'git add main.cpp'
                sh 'git commit -m "Added working C++ file"'
                sh 'git push origin main'
                echo 'Deployment Successful'
            }
        }
    }
    post {
        failure {
            echo 'Pipeline failed'
        }
    }
}
